// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "MyViewModel.generated.h"

/**
 * 
 */
UCLASS()
class VIEWMODELTESTING_API UMyViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Getter, Setter, meta=(AllowPrivateAccess))
	float MyFloat = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Getter, Setter, meta=(AllowPrivateAccess))
	int32 MyInt = 0;

public:
	void SetMyFloat(float NewFloat)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(MyFloat, NewFloat))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetMyFloatText);
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetFloat);
		}
	}

	void SetMyInt(int32 NewInt)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(MyInt, NewInt))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetMyIntText); 
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetInt);
		}
	}

public:
	float GetMyFloat() const
	{
		return MyFloat;
	}

	int32 GetMyInt() const
	{
		return MyInt;
	}

	UFUNCTION(BlueprintPure, FieldNotify)
	FText GetMyFloatText() const
	{
		return FText::AsNumber(MyFloat);
	}

	UFUNCTION(BlueprintPure, FieldNotify)
	FText GetMyIntText() const
	{
		return FText::AsNumber(MyInt);
	}

	UFUNCTION(BlueprintPure, FieldNotify)
	float GetFloat() const
	{
		return MyFloat;
	}

	UFUNCTION(BlueprintPure, FieldNotify)
	int32 GetInt() const
	{
		return MyInt;
	}
};
