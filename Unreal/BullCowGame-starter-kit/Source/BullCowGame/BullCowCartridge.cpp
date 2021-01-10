// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

 //Move outside this function

void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    Super::BeginPlay();

    // Welcoming the player
    PrintLine(TEXT("Welcome to Bull Cow game...."));
    PrintLine(TEXT("Press Enter to continue...."));
    PrintLine(TEXT("Enter Your word..."));

    // Setting Up Game
    HiddenWord = TEXT("cake");  // Set the HiddenWord
    Lives = 4; // Set Lives

    // Prompt Player Guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
        ClearScreen();
        
        // Checking PlayerGuess
        
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("Right Word"));
        }
        else
        {
            PrintLine(TEXT("Wrong Word try again!"));
            
            
        }
        
        // Check If Isogram
        // Prompt to Guess Again
        // Check Right Number of Characters
        // Prompt to Guess Again
        
        // Remove Life

        // Check if Lives > 0
        // If yes GuessAgain
        // Show Lives left
        // If no show GameOver and HiddenWord
        // Prompt yo PlayAgain, Press Enter to Play Again
        // Check user Input
       

        
}