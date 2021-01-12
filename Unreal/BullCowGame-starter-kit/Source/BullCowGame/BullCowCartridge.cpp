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

    
                
        if (bGameOver)
        {
            ClearScreen();
            SetupGame();
        }

        else //Checking PlayerGuess
        {
            if (Input == HiddenWord)
            {
                PrintLine(TEXT("Right Word"));
                EndGame();
            }
            else
            {
                 PrintLine(TEXT("You lost a life!"), --Lives);
                if(Lives > 0)
            {
                if (Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry , try again! \nYou have %i lives left "), Lives);                   
                }
                  
            }
            else
            {
                    PrintLine(TEXT("You have no lives left! "));
                    EndGame();
            }
            
            
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
            Lives = HiddenWord.Len(); // Set Lives
            bGameOver = false;
            
            PrintLine(TEXT("Guess the %i letter word...."), HiddenWord.Len());
            PrintLine(TEXT("Lives left = %i"), Lives);
            PrintLine(TEXT("Type your guess and \npress Enter to continue...."));// Prompt Player Guess                
        }

        void UBullCowCartridge::EndGame()
        {
            bGameOver = true;
            PrintLine(TEXT("Press enter to play again..."));
        }