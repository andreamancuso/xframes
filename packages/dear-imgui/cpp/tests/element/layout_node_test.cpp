#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <yoga/YGEnums.h>
#include <yoga/enums/YogaEnums.h>
#include <yoga/enums/Direction.h>
#include <yoga/enums/FlexDirection.h>
#include <yoga/enums/Edge.h>
#include <yoga/node/Node.h>
#include <yoga/style/Style.h>
#include <yoga/style/StyleLength.h>
#include <nlohmann/json.hpp>
#include <imgui_internal.h>

#include "element/layout_node.h"

using json = nlohmann::json;
using ::testing::Eq;

TEST(LayoutNode, ctor) {
    LayoutNode node;
}

TEST(LayoutNode, ApplyStyleWithEmptyJsonObject) {
    LayoutNode node;
    json styleDef;

    node.ApplyStyle(styleDef);

    EXPECT_THAT(unscopedEnum(node.GetStyle().direction()), Eq(YGDirectionInherit));
    EXPECT_THAT(unscopedEnum(node.GetStyle().flexDirection()), Eq(YGFlexDirectionColumn));
    EXPECT_THAT(unscopedEnum(node.GetStyle().justifyContent()), Eq(YGJustifyFlexStart));
    EXPECT_THAT(unscopedEnum(node.GetStyle().alignContent()), Eq(YGAlignFlexStart));
    EXPECT_THAT(unscopedEnum(node.GetStyle().alignItems()), Eq(YGAlignStretch));
    EXPECT_THAT(unscopedEnum(node.GetStyle().alignSelf()), Eq(YGAlignAuto));
    EXPECT_THAT(unscopedEnum(node.GetStyle().positionType()), Eq(YGPositionTypeRelative));
    EXPECT_THAT(unscopedEnum(node.GetStyle().flexWrap()), Eq(YGWrapNoWrap));
    EXPECT_THAT(unscopedEnum(node.GetStyle().overflow()), Eq(YGOverflowVisible));
    EXPECT_THAT(unscopedEnum(node.GetStyle().display()), Eq(YGDisplayFlex));
    EXPECT_THAT(node.GetStyle().flex(), Eq(std::numeric_limits<float>::quiet_NaN()));
    EXPECT_THAT(node.GetStyle().flexGrow(), Eq(std::numeric_limits<float>::quiet_NaN()));
    EXPECT_THAT(node.GetStyle().flexShrink(), Eq(std::numeric_limits<float>::quiet_NaN()));
    EXPECT_THAT(node.GetStyle().flexBasis(), Eq(facebook::yoga::StyleLength::ofAuto()));

    EXPECT_THAT(node.GetStyle().margin(facebook::yoga::scopedEnum(YGEdgeTop)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().margin(facebook::yoga::scopedEnum(YGEdgeRight)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().margin(facebook::yoga::scopedEnum(YGEdgeBottom)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().margin(facebook::yoga::scopedEnum(YGEdgeLeft)), Eq(facebook::yoga::StyleLength::undefined()));

    EXPECT_THAT(node.GetStyle().padding(facebook::yoga::scopedEnum(YGEdgeTop)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().padding(facebook::yoga::scopedEnum(YGEdgeRight)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().padding(facebook::yoga::scopedEnum(YGEdgeBottom)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().padding(facebook::yoga::scopedEnum(YGEdgeLeft)), Eq(facebook::yoga::StyleLength::undefined()));

    EXPECT_THAT(node.GetStyle().position(facebook::yoga::scopedEnum(YGEdgeTop)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().position(facebook::yoga::scopedEnum(YGEdgeRight)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().position(facebook::yoga::scopedEnum(YGEdgeBottom)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().position(facebook::yoga::scopedEnum(YGEdgeLeft)), Eq(facebook::yoga::StyleLength::undefined()));

    EXPECT_THAT(node.GetStyle().border(facebook::yoga::scopedEnum(YGEdgeTop)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().border(facebook::yoga::scopedEnum(YGEdgeRight)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().border(facebook::yoga::scopedEnum(YGEdgeBottom)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().border(facebook::yoga::scopedEnum(YGEdgeLeft)), Eq(facebook::yoga::StyleLength::undefined()));

    EXPECT_THAT(node.GetStyle().gap(facebook::yoga::scopedEnum(YGGutterColumn)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().gap(facebook::yoga::scopedEnum(YGGutterRow)), Eq(facebook::yoga::StyleLength::undefined()));

    EXPECT_THAT(node.GetStyle().dimension(facebook::yoga::scopedEnum(YGDimensionWidth)), Eq(facebook::yoga::StyleLength::ofAuto()));
    EXPECT_THAT(node.GetStyle().dimension(facebook::yoga::scopedEnum(YGDimensionHeight)), Eq(facebook::yoga::StyleLength::ofAuto()));

    EXPECT_THAT(node.GetStyle().minDimension(facebook::yoga::scopedEnum(YGDimensionWidth)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().minDimension(facebook::yoga::scopedEnum(YGDimensionHeight)), Eq(facebook::yoga::StyleLength::undefined()));

    EXPECT_THAT(node.GetStyle().maxDimension(facebook::yoga::scopedEnum(YGDimensionWidth)), Eq(facebook::yoga::StyleLength::undefined()));
    EXPECT_THAT(node.GetStyle().maxDimension(facebook::yoga::scopedEnum(YGDimensionHeight)), Eq(facebook::yoga::StyleLength::undefined()));

    EXPECT_THAT(node.GetStyle().aspectRatio(), Eq(std::numeric_limits<float>::quiet_NaN()));
}