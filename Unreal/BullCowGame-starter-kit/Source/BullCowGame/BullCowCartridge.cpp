// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

 

void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The Hidden Word is: %s"),*HiddenWord);  //  Debug line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

    /* 
        if game is over then ClearScreen() and RestartGame()
        else Checking PlayerGuess
    */
        if bGameOver
        {
            ClearScreen();
            SetupGame();
        }
        else
        {
            if (Input == HiddenWord)
        {
            PrintLine(TEXT("Right Word"));
            //bGameOver = true;
        }
            else
            {
                if (Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("The Hidden Word is %i characters long, try again! "),HiddenWord.Len());
                }
                
                PrintLine(TEXT("Wrong Word try again!"));
                //bGameOver = true;
            }
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

        void UBullCowCartridge::SetupGame()
        {
            // Welcoming the player
            PrintLine(TEXT("Welcome to Bull Cows...."));
            
            HiddenWord = TEXT("cakes");  // Set the HiddenWord
            Lives = 4; // Set Lives
            bGameOver = false;
            
            PrintLine(TEXT("Guess the %i letter word...."), HiddenWord.Len());
            PrintLine(TEXT("Type your guess and \npress Enter to continue...."));// Prompt Player Guess
        }

        void UBullCartridge::EndGame()
        {
            bGameOver = true;
            PrintLine(TEXT("Press enter to play again..."));
        }