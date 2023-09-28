def ft_tqdm(lst: range) -> None:
    """
    Mimics tqdm functionality... partially

    Mimics only the loading bar, percentage and chunk loaded / chunk remaining

    Cannot mimic the iterator per second count, the time taken / time remaining counter
    and the dynamic loading bar size
    due to needing external libraries, which we cannot use
    """
    blocklist = [" ", "▏", "▎", "▍", "▌", "▋", "▊", "▉"]
    max_val = max(lst) + 1
    total = max_val // len(blocklist)
    for x in lst:
        fullblocks, halfblock = divmod(x, len(blocklist))
        percentage = int(x / max_val * 100)
        print(
            f"{percentage:3}%|{(fullblocks * '█')}{blocklist[halfblock]}{' ' * (total - fullblocks)}| {x + 1}/{max_val}", end="")
        yield

        # https://stackoverflow.com/questions/5419389/how-to-overwrite-the-previous-print-to-stdout
        # If you can’t guarantee that the new line of text is not shorter than the existing line
        # then you just need to add a “clear to end of line” escape sequence, '\x1b[1K' ('\x1b' = ESC):
        print('\x1b[1K\r', end='')

    final_val, final_remain = divmod(max_val, len(blocklist))
    print(
        f"100%|{((final_val + (1 if final_remain else 0)) * '█')}| {max_val}/{max_val}", end="")
