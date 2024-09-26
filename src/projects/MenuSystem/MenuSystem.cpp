/*###############################################################################################################

    Author: Samul1
    Date: 26.09.2024

    Menu System Demo
	
	* User may use Up- and Down -arrowkeys to move in menu and select with Enter.

###############################################################################################################*/

#include<iostream>
#include<chrono>
#include<thread>
#include <stdio.h>
#include<Windows.h>
#include<string>
#include<vector>

// Will keep track if the key is pressed down or not.
struct KeyStates
{
    bool upKeyDown = false;
    bool downKeyDown = false;

    bool upKeyHandled = false;
    bool downKeyHandled = false;
};

struct Selector
{
    char selector = '*';
    size_t selectorPosition = 0;
};

struct Menu
{
	// Menu name.
	std::string menuName = "Main Menu";
    // Keep "Exit" at last index!
    std::vector<std::string> menuTexts = { "Valinta 1", "Valinta 2", "Valinta 3", "Valinta 4", "Exit"};
	std::string helpText = { "Move with arrow keys and select with \"Enter\"" };
    bool isMenuDrawn = false;
};


// Test function for "Enter-press"
bool function(Selector& selector, std::vector<std::string> menuText, bool& end)
{
    for (size_t i = 0; i < menuText.size()-1; i++)
        if (selector.selectorPosition == i)
            std::cout << menuText[i];
    if(selector.selectorPosition == menuText.size()-1)
        end = true;

    system("pause");
    return end;
}

// Method till clear the console window
void cleanScreen()
{
    system("cls");
}

// Method will move selector position 0 -> menuTexts-vector last index.
void setSelectorPosition(Selector& selector, Menu& menu, size_t keyPress)
{
    if (selector.selectorPosition == 0 && keyPress == -1)
        selector.selectorPosition = menu.menuTexts.size() - 1;
    else if (selector.selectorPosition == menu.menuTexts.size()-1 && keyPress == 1)
        selector.selectorPosition = 0;
    else
        selector.selectorPosition = selector.selectorPosition + keyPress;
}

// Method will render selector to console window
void renderSelector(Selector& selector, size_t i)
{
    if (selector.selectorPosition == i)
        std::cout << selector.selector;
    else
        std::cout << " ";
}

// Method handels main menu rendering
void renderMenu(Menu& menu, Selector& selector)
{
    if(menu.isMenuDrawn == false)
    {
        menu.isMenuDrawn = true;
		std::cout << menu.helpText << "\n" << std::endl;
        std::cout << menu.menuName << std::endl;
        for (size_t i = 0; i < menu.menuTexts.size(); i++)
        {
            std::cout << "( ";
            renderSelector(selector, i);
            std::cout << " ) " << menu.menuTexts[i] << std::endl;
        }
    }
}

// Method will handle input control
// Keys: 
// UP       - Moves selector up once
// DOWN     - Moves selector down once
// ENTER    - Enter the selected function
bool inputHandler(bool& end, KeyStates& keyState, Selector& selector, Menu& menu)
{
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        if (!keyState.upKeyDown)
        {
            // N�pp�in on pohjassa
            keyState.upKeyDown = true;
            // Nollataan tila, ett� voidaan reagoida
            keyState.upKeyHandled = false;
        }
        if (!keyState.upKeyHandled)
        {
            // Siirryt��n t�nne, kun nappi painetaan alas

            setSelectorPosition(selector, menu, -1);
            menu.isMenuDrawn = false;
            cleanScreen();

            // Merkit��n, ett� painallus on k�sitelty
            keyState.upKeyHandled = true;
        }
    }
    else
        // N�pp�in ei ole en�� pohjassa
        keyState.upKeyDown = false;

    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        if (!keyState.downKeyDown)
        {
            // N�pp�in on pohjassa
            keyState.downKeyDown = true;
            // Nollataan tila, ett� voidaan reagoida
            keyState.downKeyHandled = false;
        }
        if (!keyState.downKeyHandled)
        {
            // Siirryt��n t�nne, kun nappi painetaan alas

            setSelectorPosition(selector, menu, 1);
            menu.isMenuDrawn = false;
            cleanScreen();

            // Merkit��n, ett� painallus on k�sitelty
            keyState.downKeyHandled = true;
        }
        
    }
    else
        // N�pp�in ei ole en�� pohjassa
        keyState.downKeyDown = false;

    if (GetAsyncKeyState(VK_RETURN) & 0x8000)
    {
        function(selector, menu.menuTexts, end);
        menu.isMenuDrawn = false;
        cleanScreen();
    }
    
    return end;
}

// Method will handle inputHandler and renderMenu -method calls
bool update(bool& end, KeyStates& keystate, Selector& selector, Menu& menu)
{
    inputHandler(end, keystate, selector, menu);
    renderMenu(menu, selector);
    return end;
}

// Main function
int main()
{
    bool end = false;
    // Struct calls
    KeyStates keyStates;
    Selector selector;
    Menu menu;
    size_t deltaTime = 16;
    size_t frameCounter = 0;

    while(!end)
    {
        update(end, keyStates, selector, menu);
        
        const auto startTime = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(deltaTime));
        const auto endTime = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double, std::milli> elapsedTime = endTime - startTime;
        
        //system("cls");
        //printf("Waited: %2.5f \n", elapsedTime.count() );
    }

    std::cout << "\nThank you for rewieving this menu demo by Samul1\n";
}