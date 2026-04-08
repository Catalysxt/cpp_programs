//******************************************************************************
// Roll the dice
// 
// Description: rand() is used to simulate 10 dice rolls

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

int main() {
    srand( (int) time(nullptr));

    //std::cout << time(nullptr);
    std::cout << "Performing 10 dice rolls!\n";
    for (int i = 0; i < 10; ++i) {
        int dice = (rand() % 6) + 1;
        std::cout << dice << ((i < 10 == true) ? ', ' : ' ');
    }
}

//******************************************************************************
// Output

// Performing 10 dice rolls!
// 5, 3, 2, 4, 4, 3, 1, 6, 5, 2
//******************************************************************************
