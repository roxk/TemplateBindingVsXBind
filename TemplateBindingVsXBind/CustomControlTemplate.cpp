#include "pch.h"
#include "CustomControlTemplate.h"
#if __has_include("CustomControlTemplate.g.cpp")
#include "CustomControlTemplate.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::TemplateBindingVsXBind::implementation
{
    CustomControlTemplate::CustomControlTemplate()
    {
        InitializeComponent();
    }
}
