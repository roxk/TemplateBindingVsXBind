#pragma once

#include "CustomControl.g.h"

namespace winrt::TemplateBindingVsXBind::implementation
{
    struct CustomControl : CustomControlT<CustomControl>
    {
        CustomControl();
        void PropertyChanged(Windows::UI::Xaml::DependencyObject const& obj, Windows::UI::Xaml::DependencyProperty const& dp);
    };
}

namespace winrt::TemplateBindingVsXBind::factory_implementation
{
    struct CustomControl : CustomControlT<CustomControl, implementation::CustomControl>
    {
    };
}
