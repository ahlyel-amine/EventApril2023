<?php

  $options = array("rock", "paper", "scissors");
  $user_choice = "option";
  while ($user_choice != $options[0]
          && $user_choice != $options[1]
          && $user_choice != $options[2])
  {
    echo "Choose rock, paper, or scissors: ";
    $user_choice = strtolower(trim(fgets(STDIN)));
  }
  $computer_choice = $options[mt_rand(0, count($options)-1)];

  if ($user_choice == $computer_choice)
  {
    echo "Tie game!  The computer chose $computer_choice.";
  }
  elseif ($user_choice == "rock" && $computer_choice == "scissors" ||
  $user_choice == "paper" && $computer_choice == "rock" ||
  $user_choice == "scissors" && $computer_choice == "paper")
  {
    echo "Congratulations! You won! The computer chose $computer_choice.";
  }
  else
  {
    echo "Sorry, you lost. The computer chose $computer_choice.";
  }
?>
