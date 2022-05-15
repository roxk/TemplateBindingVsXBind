#pragma once

#include "CustomControlTemplate.g.h"

namespace winrt::TemplateBindingVsXBind::implementation
{
    struct CustomControlTemplate : CustomControlTemplateT<CustomControlTemplate>
    {
        CustomControlTemplate();
    };
}

namespace winrt::TemplateBindingVsXBind::factory_implementation
{
    struct CustomControlTemplate : CustomControlTemplateT<CustomControlTemplate, implementation::CustomControlTemplate>
    {
    };
}
