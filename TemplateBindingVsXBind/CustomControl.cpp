#include "pch.h"
#include "CustomControl.h"
#if __has_include("CustomControl.g.cpp")
#include "CustomControl.g.cpp"
#endif

namespace winrt::TemplateBindingVsXBind::implementation
{
    CustomControl::CustomControl()
    {
        DefaultStyleKey(box_value(xaml_typename<TemplateBindingVsXBind::CustomControl>().Name));
        RegisterPropertyChangedCallback(Windows::UI::Xaml::Controls::ContentControl::ContentProperty(), { get_weak(), &CustomControl::PropertyChanged });
    }
    void CustomControl::PropertyChanged(Windows::UI::Xaml::DependencyObject const& obj, Windows::UI::Xaml::DependencyProperty const& dp)
    {
        static auto i = 0;
        ++i;
    }
}
