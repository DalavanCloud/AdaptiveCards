#include "pch.h"
#include "AdaptiveImage.h"

#include "Util.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveNamespaceRef;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::UI::Xaml;
using namespace ABI::Windows::UI::Xaml::Controls;

AdaptiveNamespaceStart
    AdaptiveImage::AdaptiveImage()
    {
    }

    HRESULT AdaptiveImage::RuntimeClassInitialize() noexcept try
    {
        std::shared_ptr<AdaptiveCards::Image> image = std::make_shared<AdaptiveCards::Image>();
        return RuntimeClassInitialize(image);
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveImage::RuntimeClassInitialize(const std::shared_ptr<AdaptiveCards::Image>& sharedImage) try
    {
        if (sharedImage == nullptr)
        {
            return E_INVALIDARG;
        }

        ComPtr<IUriRuntimeClassFactory> uriActivationFactory;
        RETURN_IF_FAILED(GetActivationFactory(
            HStringReference(RuntimeClass_Windows_Foundation_Uri).Get(),
            &uriActivationFactory));
        
        std::wstring imageUri = StringToWstring(sharedImage->GetUrl());
        if (!imageUri.empty())
        {
            RETURN_IF_FAILED(uriActivationFactory->CreateUri(HStringReference(imageUri.c_str()).Get(), m_url.GetAddressOf()));
        }

        m_imageStyle = static_cast<ABI::AdaptiveNamespaceRef::ImageStyle>(sharedImage->GetImageStyle());
        m_imageSize = static_cast<ABI::AdaptiveNamespaceRef::ImageSize>(sharedImage->GetImageSize());
        m_horizontalAlignment = static_cast<ABI::AdaptiveNamespaceRef::HAlignment>(sharedImage->GetHorizontalAlignment());
        RETURN_IF_FAILED(UTF8ToHString(sharedImage->GetAltText(), m_altText.GetAddressOf()));

        GenerateActionProjection(sharedImage->GetSelectAction(), &m_selectAction);

        m_spacing = static_cast<ABI::AdaptiveNamespaceRef::Spacing>(sharedImage->GetSpacing());
        m_separator = sharedImage->GetSeparator();
        RETURN_IF_FAILED(UTF8ToHString(sharedImage->GetId(), m_id.GetAddressOf()));
        RETURN_IF_FAILED(JsonCppToJsonObject(sharedImage->GetAdditionalProperties(), &m_additionalProperties));

        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_Url(IUriRuntimeClass** url)
    {
        return m_url.CopyTo(url);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_Url(IUriRuntimeClass* url)
    {
        m_url = url;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_Style(ABI::AdaptiveNamespaceRef::ImageStyle* imageStyle)
    {
        *imageStyle = m_imageStyle;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_Style(ABI::AdaptiveNamespaceRef::ImageStyle imageStyle)
    {
        m_imageStyle = imageStyle;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_Size(ABI::AdaptiveNamespaceRef::ImageSize* imageSize)
    {
        *imageSize = m_imageSize;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_Size(ABI::AdaptiveNamespaceRef::ImageSize imageSize)
    {
        m_imageSize = imageSize;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_AltText(HSTRING* text)
    {
        return m_altText.CopyTo(text);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_AltText(HSTRING text)
    {
        return m_altText.Set(text);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_HorizontalAlignment(ABI::AdaptiveNamespaceRef::HAlignment* alignment)
    {
        *alignment = m_horizontalAlignment;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_HorizontalAlignment(ABI::AdaptiveNamespaceRef::HAlignment alignment)
    {
        m_horizontalAlignment = alignment;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_ElementType(ElementType* elementType)
    {
        *elementType = ElementType::Image;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_Spacing(ABI::AdaptiveNamespaceRef::Spacing* spacing)
    {
        *spacing = m_spacing;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_Spacing(ABI::AdaptiveNamespaceRef::Spacing spacing)
    {
        m_spacing = spacing;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_Separator(boolean* separator)
    {
        *separator = m_separator;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_Separator(boolean separator)
    {
        m_separator = separator;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_Id(HSTRING* id)
    {
        return m_id.CopyTo(id);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_Id(HSTRING id)
    {
        return m_id.Set(id);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_ElementTypeString(HSTRING* type)
    {
        ElementType typeEnum;
        RETURN_IF_FAILED(get_ElementType(&typeEnum));
        return ProjectedElementTypeToHString(typeEnum, type);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_AdditionalProperties(ABI::Windows::Data::Json::IJsonObject** result)
    {
        return m_additionalProperties.CopyTo(result);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_AdditionalProperties(ABI::Windows::Data::Json::IJsonObject* jsonObject)
    {
        m_additionalProperties = jsonObject;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::get_SelectAction(IAdaptiveActionElement** action)
    {
        return m_selectAction.CopyTo(action);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::put_SelectAction(IAdaptiveActionElement* action)
    {
        m_selectAction = action;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::ToJson(ABI::Windows::Data::Json::IJsonObject** result)
    {
        std::shared_ptr<AdaptiveCards::Image> image;
        RETURN_IF_FAILED(GetSharedModel(image));

        return StringToJsonObject(image->Serialize(), result);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImage::GetSharedModel(std::shared_ptr<AdaptiveCards::Image>& sharedImage) try
    {
        std::shared_ptr<AdaptiveCards::Image> image = std::make_shared<AdaptiveCards::Image>();

        RETURN_IF_FAILED(SetSharedElementProperties(this, std::AdaptivePointerCast<AdaptiveCards::BaseCardElement>(image)));

        if (m_selectAction != nullptr)
        {
            std::shared_ptr<BaseActionElement> sharedAction;
            RETURN_IF_FAILED(GenerateSharedAction(m_selectAction.Get(), sharedAction));
            image->SetSelectAction(sharedAction);
        }

        if (m_url != nullptr)
        {
            HString urlTemp;
            m_url->get_AbsoluteUri(urlTemp.GetAddressOf());

            std::string urlString;
            RETURN_IF_FAILED(HStringToUTF8(urlTemp.Get(), urlString));
            image->SetUrl(urlString);
        }

        if (m_altText != nullptr)
        {
            std::string out;
            RETURN_IF_FAILED(HStringToUTF8(m_altText.Get(), out));
            image->SetAltText(out);
        }
            
        image->SetImageStyle(static_cast<AdaptiveCards::ImageStyle>(m_imageStyle));
        image->SetImageSize(static_cast<AdaptiveCards::ImageSize>(m_imageSize));
        image->SetHorizontalAlignment(static_cast<AdaptiveCards::HorizontalAlignment>(m_horizontalAlignment));

        sharedImage = image;
        return S_OK;
    } CATCH_RETURN;
AdaptiveNamespaceEnd
