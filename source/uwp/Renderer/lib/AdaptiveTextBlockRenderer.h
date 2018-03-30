#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "TextBlock.h"

AdaptiveNamespaceStart
    class AdaptiveTextBlockRenderer :
        public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
        ABI::AdaptiveNamespaceRef::IAdaptiveElementRenderer,
        ABI::AdaptiveNamespaceRef::IAdaptiveElementParser>
    {
        AdaptiveRuntime(AdaptiveTextBlockRenderer)

    public:
        HRESULT RuntimeClassInitialize() noexcept;

        IFACEMETHODIMP Render(
            _In_ ABI::AdaptiveNamespaceRef::IAdaptiveCardElement* cardElement,
            _In_ ABI::AdaptiveNamespaceRef::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveNamespaceRef::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** result);

        IFACEMETHODIMP FromJson(
            ABI::Windows::Data::Json::IJsonObject *,
            ABI::AdaptiveNamespaceRef::IAdaptiveElementParserRegistration* elementParsers,
            ABI::AdaptiveNamespaceRef::IAdaptiveActionParserRegistration* actionParsers,
            ABI::AdaptiveNamespaceRef::IAdaptiveCardElement** element);
    };

    ActivatableClass(AdaptiveTextBlockRenderer);
AdaptiveNamespaceEnd
