#pragma once

#include <Geode/Geode.hpp>

// geode::TextInput::getInputNode was removed in Geode v6, so search the node tree instead
inline CCTextInputNode* findInputNode(cocos2d::CCNode* node) {
    using namespace geode::prelude;

    if (!node) return nullptr;
    if (auto textInput = typeinfo_cast<CCTextInputNode*>(node)) return textInput;
    auto children = node->getChildren();
    if (!children) return nullptr;
    for (auto child : CCArrayExt<CCNode*>(children)) {
        if (auto found = findInputNode(child)) return found;
    }
    return nullptr;
}
