#include "ItemToCraft.h"

ItemToCraft::ItemToCraft(const int s_itemId, std::vector<ReagentElement> s_reagents): 
    m_itemId{s_itemId}, m_reagents{s_reagents} {}