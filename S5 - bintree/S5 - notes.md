typedef BinTree<type> BT;

BT t1; // t1 = () = 
BT t2(value, left_tree, right_tree)
-> where value is the top node

-> note: bintrees are constant, we cannot modify it.
    though we can create a new bintree with parts from others.


t2.setOutputFormat(BT::INLINEFORMAT); // format with parenthesis
t2.setOutputFormat(BT::VISUALFORMAT); // visual pretty format

t2.left() // 
t2.right() //

t3 = t2.left().right()

t3.value()
t3.empty()

// Wrong:
// t5.left() = BT("a");
// Instead:
t5 = BT(t5.value(), BT("a"), t5.right());
