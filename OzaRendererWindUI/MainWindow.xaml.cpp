#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Microsoft.Windows.Storage.Pickers.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::OzaRendererWindUI::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
    winrt::fire_and_forget MainWindow::Open(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& )
    {
        // FileOpenPicker has no implicit default constructor in this projection.
        // Construct with nullptr to obtain an empty/activatable object reference.
        /*winrt::Microsoft::Windows::Storage::Pickers::FileOpenPicker openFilePicker{this};
        //openFilePicker.CommitButtonText(L"Choose scene to load");
        auto result{ co_await openFilePicker.PickSingleFileAsync() };
        if (result)
        {
        }
        else
        {
        }*/
        co_return;
    }
    
    winrt::fire_and_forget MainWindow::Save(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        co_return;
    }

    void MainWindow::Exit(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
    }

    /*void MainWindow::InitializeComponent()
    {
        OptionVulkan();
		currentRenderMode = renderMode::Vulkan;
    }*/

    void MainWindow::UseDirectX(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        currentRenderMode = renderMode::DirectX;
    }

    void MainWindow::UseVulkan(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        currentRenderMode = renderMode::Vulkan;
    }

    void MainWindow::UseOpenGL(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        currentRenderMode = renderMode::OpenGL;
    }
}
