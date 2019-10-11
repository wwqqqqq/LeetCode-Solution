Select Firstname, LastName, City, State from Person
Left join Address on Person.PersonId = Address.PersonId;
