
from crossword_solver import CrosswordSolver

solver = CrosswordSolver(6,5,1)

solver.block(1,0)
solver.block(1,1)
solver.block(1,3)
solver.block(2,0)
solver.block(3,1)
solver.block(5,1)
solver.block(5,2)
solver.block(5,4)

solver.add_id(0,0,1)
solver.add_id(0,2,2)
solver.add_id(0,4,3)
solver.add_id(2,1,4)
solver.add_id(2,3,5)
solver.add_id(3,0,6)
solver.add_id(3,2,7)
solver.add_id(4,0,8)

solver.add_word(1,0,"hoses")
solver.add_word(1,0,"laser")
solver.add_word(1,0,"sheet")
solver.add_word(1,0,"steer")
solver.add_word(1,0,"sails")

solver.add_word(4,0,"heel")
solver.add_word(4,0,"hike")
solver.add_word(4,0,"keel")
solver.add_word(4,0,"knot")
solver.add_word(4,0,"line")

solver.add_word(7,0,"aft")
solver.add_word(7,0,"ale")
solver.add_word(7,0,"eel")
solver.add_word(7,0,"lee")
solver.add_word(7,0,"tie")

solver.add_word(8,0,"hoses")
solver.add_word(8,0,"laser")
solver.add_word(8,0,"sheet")
solver.add_word(8,0,"steer")
solver.add_word(8,0,"sails")

solver.add_word(2,1,"hoses")
solver.add_word(2,1,"laser")
solver.add_word(2,1,"sheet")
solver.add_word(2,1,"steer")
solver.add_word(2,1,"sails")

solver.add_word(3,1,"hoses")
solver.add_word(3,1,"laser")
solver.add_word(3,1,"sheet")
solver.add_word(3,1,"steer")
solver.add_word(3,1,"sails")

solver.add_word(5,1,"heel")
solver.add_word(5,1,"hike")
solver.add_word(5,1,"keel")
solver.add_word(5,1,"knot")
solver.add_word(5,1,"line")

solver.add_word(6,1,"aft")
solver.add_word(6,1,"ale")
solver.add_word(6,1,"eel")
solver.add_word(6,1,"lee")
solver.add_word(6,1,"tie")

ans = solver.solve()


print("-"*35)
for i in ans:
    for j in i:
        print(j,end=" ");
    print("")
print("-"*35)

