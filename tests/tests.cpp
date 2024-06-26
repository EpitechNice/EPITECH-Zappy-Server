#include <gtest/gtest.h>

extern "C" {
    #include "ai.h"
    #include "gui.h"
}

// ========== DList ==========

void DList_add_two(void* data)
{
    int* nb = (int*)data;
    *nb += 2;
}

void DList_add_x(void* data, void* x)
{
    int* nb = (int*)data;
    int add = *(int*)x;

    *nb += add;
}

bool DList_cmp_start_with(void* _ref, void* _data)
{
    char* ref = (char*)_ref;
    char* data = (char*)_data;

    return strncmp(ref, data, strlen(ref)) == 0;
}

void DList_displ_and_free(void* data)
{
    std::cout << (char*)data;
    &free(data);
}

bool DList_cmp_string(void* _ref, void* _data)
{
    std::string ref = (char*)_ref;
    std::string data = (char*)_data;

    return ref == data;
}

TEST(DList, DL_Apply)
{
    lnode_t* node = NULL;
    int n = 5;

    dl_push_back(&node, &n);
    dl_apply_data(node, &DList_add_two);

    EXPECT_EQ(*(int*)node->data, 7) << "Could not add_two to the element of the list";

    int nb_to_add = 9;

    dl_apply_data_param(node, &DList_add_x, &nb_to_add);

    EXPECT_EQ(*(int*)node->data, 16) << "Could not add_x to the element of the list";

    dl_clear(&node, NULL);
}

TEST(DList, DL_Empty)
{
    lnode_t* node = NULL;

    int n = 42;

    EXPECT_TRUE(dl_empty(node)) << "NULL list isn't empty";

    dl_push_back(&node, &n);

    EXPECT_FALSE(dl_empty(node)) << "Non-NULL list is empty";

    dl_clear(&node, NULL);
}

TEST(DList, DL_Erase)
{
    lnode_t* node = NULL;
    char underscore[2] = "_";

    dl_push_back(&node, strdup("This string does not start with an underscore"));
    dl_push_back(&node, strdup("_ This string starts with an underscore"));
    dl_push_back(&node, strdup("This string does not start with an underscore either"));

    testing::internal::CaptureStdout();
    dl_erase(&node, underscore, &DList_cmp_start_with, &DList_displ_and_free);
    std::string stdout = testing::internal::GetCapturedStdout();

    EXPECT_EQ(stdout, "_ This string starts with an underscore") << "dl_erase did not remove the wanted elements";

    dl_clear(&node, &free);
}

TEST(DList, DL_Extract)
{
    lnode_t* node = NULL;
    char underscore[2] = "_";

    dl_push_back(&node, strdup("This string does not start with an underscore"));
    dl_push_back(&node, strdup("_ This string starts with an underscore"));
    dl_push_back(&node, strdup("This string does not start with an underscore either"));

    std::string element = (char*)dl_extract(&node, underscore, &DList_cmp_start_with);

    EXPECT_EQ(element, "_ This string starts with an underscore") << "dl_extract did not extract the wanted element";

    dl_clear(&node, &free);
}

TEST(DList, DL_Find)
{
    lnode_t* node = NULL;
    char ref[] = "String n°2";

    dl_push_back(&node, strdup("String n°1"));
    dl_push_back(&node, strdup("String n°2"));
    dl_push_back(&node, strdup("String n°3"));

    std::string element = (char*)dl_find_data(node, ref, &DList_cmp_string);

    EXPECT_EQ(element, "String n°2") << "dl_find did not retreive the wanted element";

    dl_clear(&node, &free);
}

TEST(DList, DL_Length)
{
    lnode_t* node = NULL;

    EXPECT_EQ(dl_length(node), 0) << "dl_length did not return 0 on NULL list";

    dl_push_back(&node, strdup("alpha"));
    EXPECT_EQ(dl_length(node), 1) << "dl_length did not return valid output";

    dl_push_back(&node, strdup("bravo"));
    EXPECT_EQ(dl_length(node), 2) << "dl_length did not return valid output";

    dl_push_back(&node, strdup("charlie"));
    EXPECT_EQ(dl_length(node), 3) << "dl_length did not return valid output";

    dl_clear(&node, &free);
}

TEST(DList, DL_Pop)
{
    lnode_t* node = NULL;
    char* data = strdup("Hello world!");
    char* data2 = strdup("Not Hello world");
    dl_push_back(&node, data);
    dl_push_back(&node, data2);

    void* out = dl_pop_front(&node);
    EXPECT_EQ(out, data) << "Poped data is not what expected: " << out << " != " << data;

    dl_push_front(&node, data);

    out = dl_pop_back(&node);
    EXPECT_EQ(out, data2) << "Poped data is not what expected: " << out << " != " << data2;

    dl_clear(&node, &free);
}

TEST(DList, DL_Push)
{
    lnode_t* node = NULL;
    char* data = strdup("Hello world!");
    dl_push_back(&node, data);

    EXPECT_EQ(strcmp((char*)node->data, data), 0) << "String found on node is not the same as passed as argument";
    EXPECT_EQ(node->data, data) << "Data passed in argument has moved in memory";

    char* other_data = strdup("Not Hello world");
    dl_push_front(&node, other_data);

    EXPECT_NE(strcmp((char*)node->data, data), 0) << "First element is still \"Hello world!\"";

    dl_clear(&node, &free);
}

// ========== Logging ==========

TEST(Logging, Set_Log_Level)
{
    log_level_t level = LOG_LEVEL_CRITICAL;

    set_log_level(level);

    EXPECT_EQ(level, get_log_level()) << "set_log_level did not change the level";
}

// ========== Core ==========