#include "MainComponent.h"

template<class ButtonType>
auto makeButton(ButtonType* buttonToMakeUnique) -> std::unique_ptr<ButtonType>
{
    return std::unique_ptr<ButtonType>(buttonToMakeUnique);
}

//==============================================================================
MainComponent::MainComponent()
{
//   ButtonWrapper<TextButton> button(nullptr)
//    ButtonWrapper<DrawableButton>(<#std::function<void ()> onClickHandler#>,
//                                    const String &buttonName,
//                                    const ButtonStyle buttonStyle)
    
    heapButton.reset(new HeapButtonWrapper<TextButton>([](){ DBG ("You clicked the heap"); },
                                                new TextButton("heapButton")
                                                       )
                     );
    addAndMakeVisible(button);
    
    addAndMakeVisible( (*heapButton) );
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (32.0f));
    g.setColour (juce::Colours::green);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centredLeft, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
    button->setBounds(269,
                      154,
                      100,
                      30 );
    
    (*heapButton)->setBounds(270,
                             0,
                             100,
                             30);
}
