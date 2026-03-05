// DESCRIPTION: Compares two integers and returns true if they are
// equal.
//
// ARGUMENTS(INPUT): arg1- { x ∈ ℤ | 0 ≤ x ≤ 100 }
//                   arg2- { x ∈ ℤ | 0 ≤ x ≤ 100 }
//
// SIDE EFFECTS: None
//
// RETURN(OUTPUT): True- The two integers are equal
//                 False- The two integers are not equal
constexpr int MAX_VALUE = 100;

auto IsEqual(int arg1, int arg2) -> bool {
  // Check Domain|Precondition
  if (arg1 < 0 || arg1 > MAX_VALUE || arg2 < 0 || arg2 > MAX_VALUE) {
    return false;
  }

  return arg1 == arg2;
}
