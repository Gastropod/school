#include "hw4_header.h"

AptNode::AptNode()
{
    char* temp_chars = new char[100]; // Go ahead and make this large because it is temp and shared
    // For name, get input in temp then put in dynamically allocated array name
    cout << "Complex Name:" << endl;
    cin.get(temp_chars, 100, '\n'); // Apt Complex Name
    cin.ignore(100, '\n');
    name = new char[strlen(temp_chars)+1];
    strcpy(name, temp_chars);
    // For comment, get input in temp then put in dynamically allocated array name
    cout << "Comment:" << endl;
    cin.get(temp_chars, 100, '\n'); // Apt Complex Name
    cin.ignore(100, '\n');
    comment = new char[strlen(temp_chars)+1];
    strcpy(comment, temp_chars);
    // Simple inputs
    cout << "Size of Unit (sq ft)(Whole number.):" << endl;
    cin >> sq_ft; // Size of unit
    cout << "Number of Bedrooms (Whole number.):" << endl;
    cin >> beds; // Bedroom count, whole numbers
    cout << "Number of Bathrooms (Can be decimal):" << endl;
    cin >> baths; // Bathroom count, fractionable
    cout << "Rent Cost (Nearest whole dollar.):" << endl;
    cin >> rent; // Rent monthly, nearest dollar
    cout << "Are pets allowed?" << endl;
    pets = _prompt_bool(); // True if pets allowed
    cout << "Is a dishwasher included?" << endl;
    dish = _prompt_bool(); // True if dishwasher machine included
    cout << "Are washer/dryer included?" << endl;
    laundry = _prompt_bool(); // True if washer/dryer included
}

// Return "Yes" or "No" in place of true of false
void AptNode::_bool_to_chars(bool val, char msg[])
{
    char yes[5] = "Yes.";
    char no[5] = "No.";
    if (val)
    {
        strcpy(msg, yes);
    } else { 
        strcpy(msg, no);
    }
}

// Prompt and get apartment info from the input stream
bool AptNode::_prompt_bool()
{
	// This repeatedly prompts the user for a yes or no response until valid input is provided.
	int i = 0;
	char response;
	while (i=0, i++, i<5)
	{
		// Prompt user for boolean response.
		cout << "Please respond with 'y' (yes) or 'n' (no)." << endl;
		cin >> response;
		cin.ignore(100, '\n');
		// Process input and return true or false if input was valid.
		if (response=='y')
		{
			return true;
		} else if (response=='n')
		{
			return false;
		} else
		{
			// Invalid response. Inform user and try again.
			cout << "Invalid response..." << endl;
		}
	}
	// Give up because user has exceeded tries limit. Assume the assignment was graded.
	cout << "This is taking too long. I'll answer for you... 'y'." << endl;
	return true;
}

// Writes apt info as a new line to an open file
void AptNode::to_file(ofstream* outfile)
{
    *outfile << endl
    << name << ':' // Apt Complex Name
    << sq_ft << ':'  // Size of unit
    << beds << ':'  // Bedroom count, whole numbers
    << baths << ':'  // Bathroom count, fractionable
    << rent << ':'  // Rent monthly, nearest dollar
    << pets << ':'  // True if pets allowed
    << dish << ':'  // True if dishwasher machine included
    << laundry // True if washer/dryer include
    ;
}

// Reads apt info from open file
void AptNode::from_file(ifstream* infile)
{
    infile->get(name, 100, ':'); // Apt Complex Name
    infile->ignore(100, ':');
    *infile >> sq_ft; // Size of unit
    infile->ignore(100, ':');
    *infile >> beds; // Bedroom count, whole numbers
    infile->ignore(100, ':');
    *infile >> baths; // Bathroom count, fractionable
    infile->ignore(100, ':');
    *infile >> rent; // Rent monthly, nearest dollar
    infile->ignore(100, ':');
    *infile >> pets; // True if pets allowed
    infile->ignore(100, ':');
    *infile >> dish; // True if dishwasher machine included
    infile->ignore(100, ':');
    *infile >> laundry; // True if washer/dryer included
    infile->ignore(100, '\n');
}

// Display the info of an apartment
void AptNode::display_apt()
{
    char pets_chars[5];
    char dish_chars[5];
    char laundry_chars[5];

    _bool_to_chars(pets, pets_chars);
    _bool_to_chars(dish, dish_chars);
    _bool_to_chars(laundry, laundry_chars);
    cout 
        << "Complex Name:" << '\n'
        << '\t' << name << '\n' // Apt Complex Name
        << "Size of Unit (sq ft):" << '\n'
        << '\t' << sq_ft << '\n' // Size of unit
        << "Number of Bedrooms:" << '\n'
        << '\t' << beds << '\n' // Bedroom count, whole numbers
        << "Number of Bathrooms:" << '\n'
        << '\t' << baths << '\n' // Bathroom count, fractionable
        << "Rent Cost:" << '\n'
        << '\t' << rent << '\n' // Rent monthly, nearest dollar
        << "Pets allowed:" << '\n'
        << '\t' << pets_chars << '\n' // True if pets allowed
        << "Dishwasher included:" << '\n'
        << '\t' << dish_chars << '\n' // True if dishwasher machine included
        << "Washer/dryer included:" << '\n'
        << '\t' << laundry_chars // True if washer/dryer included
        << endl;
}