#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(comp);
    comp.addMouseListener(this, false);
    
    addAndMakeVisible(ownedArrayComp);
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
    comp.removeMouseListener(this);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    comp.setBounds(30, 30, 100, 100);
    ownedArrayComp.setBounds(comp.getX(),
                             comp.getBottom() + 5,
                             getWidth() - comp.getX(),
                             getHeight() - comp.getBottom());

}
