#include "BattleShips/Public/Components/HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	check (MaxHealth > 0);

	Health = MaxHealth;
	OnHealthChanged.Broadcast(Health);

	if (AActor* ComponentOwner = GetOwner())
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnTakeAnyDamageHandle);
	}
}

void UHealthComponent::OnTakeAnyDamageHandle(AActor* DamagedActor, float Damage,
	const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0 || IsDead())
	{
		return;
	}
	
	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
	
	OnHealthChanged.Broadcast(Health);
	
	if (IsDead())
	{
		OnDeath.Broadcast();
	}
}



