import random

class Family:

    def __init__(self,first, last, hair):
        self.first = first
        self.last = last
        self.hair = hair


    def fullname(self):
        return '{} {}'.format(self.first,self.last)


    def eyefind(self):
        temp = random.choice([1,2])
        #using the punnet square in genetics we know thatt a donor
        #with blue eyes and one with brown makes it 50/50 odds
        #that the childs eyes will be brown or blue
        if (temp == 1):
            self.EYES = ("Brown")
        else:
            self.EYES = ("Blue")
        return self.EYES

    def Apply_eyes(self):
        self.eyes = self.EYES

Daughter = Family('Ashley', 'Smith', 'Brown')
Son = Family('Kevin', 'Smith', 'Brown')

print(Daughter.eyes)
print(Son.eyes)


#with the kids being born it will define what color hair and eyes 
# they may randomly get through inheritance

class Kids(Family):
    pass
#Eyes are marked as Grey because they are unknown for now
# hair colors are brown because brown is the dominant hair color
    Daughter = Kids('Danielle', 'Smith', 'Brown' )
    Son = Kids('Kevin','Smith','Brown')

    print(Daughter.eyes)
    print(Son.eyes)

    Daughter.Apply_eyes()
    Son.Apply_eyes()
    
    print(Daughter.eyes)
    print(Son.eyes)
    

    