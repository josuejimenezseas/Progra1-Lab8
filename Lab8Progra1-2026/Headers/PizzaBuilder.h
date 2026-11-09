#pragma once
#include <vector>
#include <string>
#include "TomatoesRepository.h"
#include "IngredientSelector.h"
#include "../HerbsRepository.h"

class PizzaBuilder {
public:
    PizzaBuilder();

    void BuildPizza();
    void DisplayFinalPizza() const;

private:
    void WaitForEnterAndClear();
    bool QuiereSeguirAgregandoTomate();
    bool QuiereSeguirAgregandoHerbs();
    void SelectTomatoes();
    void SelectHerb();
    void IrAlSiguienteIngrediente();
    void SelectCheese();
    void SelectMeat();
    void MostrarGrupo(const std::string& nombre, const std::vector<std::string>& ingredientes) const;
    int ContarTiposAgregados() const;

    TomatoesRepository tomatoRepo_;
    HerbsRepository herbsRepository;

    std::vector<std::string> selectedTomatoes_;
    std::vector<std::string> selectedCheeses_;
    std::vector<std::string> selectedMeats_;
    std::vector<std::string> selectedHerbs_;

    const std::vector<std::string> availableTomatoes_ = { "Cherry", "Roma", "Beefsteak", "Heirloom", "Grape" };
    const std::vector<std::string> availableHerbs_ = { "Basil", "Parsley", "Oregano", "Thyme", "Rosemary", "Cilantro", "Sage", "Chives" };
};