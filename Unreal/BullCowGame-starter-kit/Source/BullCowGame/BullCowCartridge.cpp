// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

 //Move outside this function

void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cow game...."));
    PrintLine(TEXT("Press Enter to continue...."));
    HiddenWord = TEXT("cake");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
        ClearScreen();
        

        if (Input == HiddenWord)
        {
            PrintLine(TEXT("Right Word"));
        }
        else
        {
            PrintLine(TEXT("Wrong Word try again!"));
        }
        
}