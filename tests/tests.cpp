#include <gtest/gtest.h>

extern "C" {
    #include "ai.h"
    // #include "gui.h"
}

// ========== DList ==========

TEST(DList, DL_Push)
{
    lnode_t* node = NULL;
    char* data = strdup("Hello world!");
    dl_push_back(&node, data);

    EXPECT_EQ(strcmp((char*)node->data, data), 0) << "String found on node is not the same as passed as argument";
    EXPECT_EQ(node->data, data) << "Data passed in argument has moved in memory";

    char *other_data = strdup("Before Hello world");
    dl_push_front(&node, other_data);

    EXPECT_NE(strcmp((char*)node->data, data), 0) << "First element is still \"Hello world!\"";

    dl_clear(&node, free);
}

TEST(DList, DL_Pop)
{
    lnode_t* node = NULL;
    char* data = strdup("Hello world!");
    dl_push_back(&node, data);
    dl_push_back(&node, strdup(data));

    void *out = dl_pop_front(&node);
    EXPECT_EQ(out, data) << "Poped data is not what expected";

    dl_push_front(&node, data);

    out = dl_pop_back(&node);
    EXPECT_EQ(out, data) << "Poped data is not what expected";
}

// ========== Input_Output ==========

// ========== Core ==========