#pragma once

#include "MainPage.g.h"

namespace winrt::TemplateBindingVsXBind::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();
        void PropertyChanged(event_token token) { mChanged.remove(token); }
        event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler) { return mChanged.add(handler); }
        hstring Text() { return mText; }
        hstring Time() { return mTime; }
    private:
        hstring mText;
        hstring mTime;
        event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> mChanged;
    public:
        void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::TemplateBindingVsXBind::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
