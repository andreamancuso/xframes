#include "widget/styled_widget.h"
#include "widget/child.h"

Child::Child(ReactImgui* view, const int id, const float width, const float height, std::optional<BaseStyle>& style) : StyledWidget(view, id, style) {
    m_type = "Child";
    m_handlesChildrenWithinRenderMethod = true;

    m_width = width;
    m_height = height;
};

void Child::Render(ReactImgui* view) {
    ImGui::PushID(m_id);
    ImGui::BeginChild("", ImVec2(m_width, m_height), m_flags);
    Widget::HandleChildren(view);
    ImGui::EndChild();
    ImGui::PopID();
};

void Child::Patch(const json& widgetPatchDef, ReactImgui* view) {
    if (widgetPatchDef.is_object()) {
        StyledWidget::Patch(widgetPatchDef, view);

        if (widgetPatchDef["width"].is_string()) {
            m_width = widgetPatchDef["width"].template get<float>();
        }
        if (widgetPatchDef["height"].is_string()) {
            m_height = widgetPatchDef["height"].template get<float>();
        }
    }
};