# Jak 72 Cell Randomiser

A simple C++ script to randomise the cell order for a No LTS speedrun. Should take into account all possible softlocks and prevent them.

General flow of the code:

The script loops and picks cells from a valid list, which starts with just the 4 geyser cells. This list gets added to as and when cells become obtainable.

A multitude of if statements check for possible additions to be made to the list every loop.

Some also prevent a randomly selected cell from being used (in the case of too many purchasable cells).

Once the loop is finished it randomly places the order to watch/skip red sage, making sure it happens after hub 2/3 are unlocked but far enough before a Snowy cell is selected.

Finally it prints out the generated list, with additional text fitted appropriately.

The softlocks prevented:

- Misty cells before fish cell
- Temple cells before top of temple cell
- FC cells before 20 cells collected
- Too many purchasable cells before misty or hub 2/3 unlocked
- Hub 2/3 cells before FC end cell
- Snowy cells before at least 2 additional cells have been collected after FC end cell
- Too many purchasable cells before misty or snowy unlocked
