#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Storage.Pickers.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <Microsoft.UI.Xaml.Window.h>
#include <winrt/Microsoft.Windows.Storage.Pickers.h>
#include <ShObjIdl.h>
#include <fstream>

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
        auto windowNative{ (static_cast<winrt::Microsoft::UI::Xaml::Window>(*this)).as<::IWindowNative>() };
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd); 
        Windows::Storage::Pickers::FileOpenPicker openFilePicker;
        auto initializeWithWindow{ openFilePicker.as<::IInitializeWithWindow>() };
        openFilePicker.CommitButtonText(L"Choose scene to load");
        openFilePicker.FileTypeFilter().ReplaceAll({ L".oscn" });
        initializeWithWindow->Initialize(hWnd);        
        auto result{ co_await openFilePicker.PickSingleFileAsync() };
        if (result)
        {
			std::ofstream file{ result.Path().c_str() };
			scene.loadScence(file);
        }
        else
        {
        }
        co_return;
    }
    
    winrt::fire_and_forget MainWindow::Save(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        auto windowNative{ (static_cast<winrt::Microsoft::UI::Xaml::Window>(*this)).as<::IWindowNative>() };
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);
        Windows::Storage::Pickers::FileSavePicker saveFilePicker;
        auto initializeWithWindow{ saveFilePicker.as<::IInitializeWithWindow>() };
        //saveFilePicker.CommitButtonText(L"Choose scene to load");
        //saveFilePicker.FileTypeFilter().ReplaceAll({ L".oscn" });
        initializeWithWindow->Initialize(hWnd);
        auto result{ co_await saveFilePicker.PickSaveFileAsync() };
        if (result)
        {
        }
        else
        {
        }
        co_return;
    }

    void MainWindow::Exit(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
		exit(0);
    }

    void MainWindow::InitializeComponent()
    {
        MainWindowT<MainWindow>::InitializeComponent();
        OptionVulkan().IsChecked(true);
		currentRenderMode = renderMode::Vulkan;
    }

    void MainWindow::UseDirectX(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        currentRenderMode = renderMode::DirectX;
		OptionVulkan().IsChecked(false);
		OptionOpenGL().IsChecked(false);
    }

    void MainWindow::UseVulkan(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        currentRenderMode = renderMode::Vulkan;
		OptionDirectX().IsChecked(false);
		OptionOpenGL().IsChecked(false);
    }

    void MainWindow::UseOpenGL(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        currentRenderMode = renderMode::OpenGL;
		OptionVulkan().IsChecked(false);
		OptionDirectX().IsChecked(false);
    }
}
