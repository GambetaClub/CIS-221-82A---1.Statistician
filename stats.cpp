// Provided by:   ____________(your name here)__________
// Lab:           ____________(the lab number here)________
// Course number: ____________(the course number here)________
// FILE: stats.h
// CLASS PROVIDED: Statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace main_savitch_2C.
//
// VALUE SEMANTICS for the Statistician class:
// Assignments and the copy constructor may be used with Statistician objects.

#include "stats.h"
#include <assert.h>
 
namespace main_savitch_2C
{
  //  Postcondition: The object has been initialized, and is ready to accept
  //  a sequence of numbers. Various statistics will be calculated about the
  //  sequence.
  Statistician::Statistician( )
  {
      count_ = 0;
  }

  //  The number r has been given to the Statistician as the next number in
  //  its sequence of numbers.
  void Statistician::next(double r)
  {
      if (count_ == 0){
          total_ = r;
          tinyest_ = r;
          largest_ = r;
      }
      else{
          total_ += r;
          if (tinyest_ > r){
              tinyest_ = r;
          }
          if (largest_ < r){
              largest_ = r;
          }
      }
      count_++;
  }

  //  Postcondition: The Statistician has been cleared, as if no numbers had
  //  yet been given to it.
  void Statistician::reset( )
  {
      count_ = 0;
  }

  //  Postcondition: The return value is the length of the sequence that has
  //  been given to the Statistician (i.e., the number of times that the
  //  next(r) function has been activated).
  int Statistician::length( ) const
  {
    return count_;
  }

  //  Postcondition: The return value is the sum of all the numbers in the
  //  Statistician's sequence.
  double Statistician::sum( ) const
  {
    return total_;
  }

  //  Precondition: length( ) > 0
  //  Postcondition: The return value is the arithmetic mean (i.e., the
  //  average of all the numbers in the Statistician's sequence).
  double Statistician::mean( ) const
  {
    assert(count_ > 0);
    double mean = total_ / count_;
    return mean;
  }
    
  //  Precondition: length( ) > 0
  //  Postcondition: The return value is the tinyest number in the
  //  Statistician's sequence.
  double Statistician::minimum( ) const
  {
    assert(count_ > 0);
    return tinyest_;
  }
    
  //  Precondition: length( ) > 0
  //  Postcondition: The return value is the largest number in the
  //  Statistician's sequence.
  double Statistician::maximum( ) const
  {
    assert(count_ > 0);
    return largest_;
  }
    
  //  Postcondition: The Statistician that is returned contains all the
  //  numbers of the sequences of s1 and s2.
  Statistician operator + (const Statistician& s1,
			   const Statistician& s2)
  {
    if (s1.length() == 0){
        return s2;
    }
    if (s2.length() == 0){
        return s1;
    }
    Statistician stat;
    if(s1.maximum() >= s2.maximum()){
        stat.largest_ = s1.maximum();
    }
    else{
        stat.largest_ = s2.maximum();
    }
    if(s1.minimum() <= s2.minimum()){
        stat.largest_ = s1.minimum();
    }
    else{
        stat.largest_ = s2.minimum();
    }
    stat.count_ = s1.length() + s2.length();
    stat.total_ = s1.sum() + s2.sum();
    return stat;
  }

  //  Postcondition: The Statistician that is returned contains the same
  //  numbers that s does, but each number has been multiplied by the
  //  scale number.
  Statistician operator * (double scale,
			   const Statistician& s)
  {
    Statistician stat;
    stat.largest_ = s.maximum() * scale;
    stat.tinyest_ = s.minimum() * scale;
    stat.count_ = s.length() * scale;
    stat.total_ = s.sum() * scale;
    return stat;
  }

  //  Postcondition: The return value is true if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  have the same length, the same  mean, the same minimum, 
  //  the same maximum, and the same sum.
  bool operator ==(const Statistician& s1,
                   const Statistician& s2)
  {
    if(s1.length() == s2.length() && s1.sum() == s2.sum() &&
    s1.maximum() == s2.maximum() && s1.minimum() == s2.minimum()){
            return true;
        }
    else{
        return false;
    }
  }

  //  Postcondition: The return value is false if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  not have the same length, the same  mean, the same minimum, 
  //  the same maximum, and the same sum.
  bool operator !=(const Statistician& s1,
                   const Statistician& s2)
  {
    if(s1.length() == 0 && s2.length() == 0){
        return false;
    }
    if(s1.length() == s2.length() && s1.sum() == s2.sum() &&
    s1.maximum() == s2.maximum() && s1.minimum() == s2.minimum()){
        return false;
    }
    else{
        return true;
    }

  }
}