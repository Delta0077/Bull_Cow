// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

 

void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    Super::BeginPlay();
    ;
    SetupGame();

    PrintLine(TEXT("The number of possible word is %i"), Words.Num());
    PrintLine(TEXT("The number of valid words is: %i."), GetValidWords(Words).Num());
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
        ProcessGuess(Input);
    }
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

        /* const TCHAR HW[] = TEXT("cakes");     
        PrintLine(TEXT("character 1 of the hidden word is: %c"), HiddenWord[0]); */           
    }

    void UBullCowCartridge::EndGame()
    {
        bGameOver = true;
        PrintLine(TEXT("Press enter to play again..."));
    }

    void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("Right Word"));
        EndGame();
        return;
    }
               
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letters long."), HiddenWord.Len());
        PrintLine(TEXT("Sorry , try again! \nYou have %i lives left. "), Lives);  
        return;                 
    }

        // Check If Isogram
    if(!bIsIsogram(Guess))
    {
                    
        PrintLine(TEXT("No repeating letters, guess again!"));
        return;
    }
               
        // Remove Life

        PrintLine(TEXT("You lost a life!"));
        --Lives;

    if (Lives <= 0)
    {    
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }
        //Show the player Bulls and Cows
        PrintLine(TEXT("Try guessing again, you have %i lives left"), Lives);
}

    bool UBullCowCartridge::bIsIsogram(FString Word) const
{
        
        for(int32 Index = 0; Index < Word.Len(); Index++)
            {
                for(int32 Compare = Index + 1; Compare < Word.Len(); Compare++)
                {

                if(Word[Index] == Word[Compare])
                {
                    return false;
                }
                }
            }
            return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(TArray<FString> WordList) const
{
    TArray<FString> ValidWords;

        for  (FString Word : WordList) //Range based for loop
        {   
            if(Word.Len() >= 4 && Word.Len() <= 8 && bIsIsogram(Word))
        {
            ValidWords.Emplace(Word);    
        }
    }
    return ValidWords;

}
