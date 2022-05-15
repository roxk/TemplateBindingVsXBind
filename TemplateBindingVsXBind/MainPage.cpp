#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <winrt/Windows.ApplicationModel.Core.h>
#include <chrono>

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::TemplateBindingVsXBind::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
        Windows::ApplicationModel::Core::CoreApplication::GetCurrentView().TitleBar().ExtendViewIntoTitleBar(false);
        mText = L"clicked=false";
        mTime = L"not ran yet";
    }
}


void winrt::TemplateBindingVsXBind::implementation::MainPage::Button_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Windows::UI::Xaml::RoutedEventArgs const&)
{
    auto now = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000'000; ++i)
    {
        mText = hstring(L"clicked=") + (i % 2 == 1 ? L"true" : L"false");
        mChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs(L"Text"));
    }
    auto elapsed = std::chrono::steady_clock::now() - now;
    auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
    mTime = to_hstring(elapsedMs.count()) + L"ms";
    mChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs(L"Time"));
}
