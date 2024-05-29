
# Voting System

This project is a simple voting system application written in C++. It allows users to cast votes for various parties, view the winning party, see the total number of votes cast, update voter details, and delete voter records.

## Features

- **Cast a Vote**: Users can cast their vote by entering their details and choosing a party.
- **See Winning Party**: Displays the current winning party based on the votes cast.
- **Total Votes Count**: Shows the total number of votes cast.
- **Update Voter Details**: Allows updating the details of a voter by their ID.
- **Delete Voter Record**: Allows deleting a voter record by their ID.

## Prerequisites

- C++ compiler (e.g., g++, clang++)
- A terminal or command prompt

## Installation

1. **Clone the repository**:
   ```sh
   git clone https://github.com/yourusername/voting-system.git
   cd voting-system
   ```

2. **Build the project**:
   ```sh
   g++ -o voting_system voting_system.cpp
   ```

## Usage

1. **Run the application**:
   ```sh
   ./voting_system
   ```

2. **Login**:
   - **Username**: `DSP`
   - **Password**: `MyDSP1`

3. **Menu Options**:
   - **1. Cast a Vote**: Enter name, age, state, voter ID, and party to cast a vote.
   - **2. See Winning Party**: Displays the party currently winning the votes.
   - **3. See Total Number of Votes Casted**: Shows the total number of votes cast.
   - **4. Update a Voter by ID**: Update details of a voter using their ID.
   - **5. Delete a Voter by ID**: Delete a voter record using their ID.
   - **6. Exit**: Exit the application.

## Data File

- The application uses a data file named `initial_data.txt` to store voter information.
- Each line in the file contains the following details for a voter: `name age state voterId party`.

## Code Structure

- **Voter Class**: Represents a voter with attributes like name, age, state, voter ID, and party.
- **VoterFunctions Class**: Provides functionalities such as inserting, updating, deleting voters, saving to file, and displaying voter details.

## Example Data File

Here's an example `initial_data.txt` file:

```
John 30 California 101 1
Jane 25 Texas 102 2
Doe 40 NewYork 103 3
```

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your changes.


## Acknowledgements

- Thanks to all contributors and supporters of this project.

---

Feel free to customize the content and structure based on your specific needs and preferences.
