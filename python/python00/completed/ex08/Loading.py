def ft_tqdm(lst: range) -> None:
    """
    Mimics tqdm functionality... partially

    Mimics only - the loading bar
                - percentage and chunk loaded
                - chunk remaining

    Cannot mimic - the iterator per second count
                 - the time taken / time remaining counter
                 - the dynamic loading bar size

    due to needing external libraries, which we cannot use
    """
    blocklist = [" ", "▏", "▎", "▍", "▌", "▋", "▊", "▉"]
    max_val = max(lst) + 1
    total = max_val // len(blocklist)
    for x in lst:
        full, half = divmod(x, len(blocklist))
        percent = int(x / max_val * 100)
        symbol = blocklist[half]
        fb_str = full * '█'
        empty_str = ' ' * (total - full)
        print(
            f"{percent:3}%|{fb_str}{symbol}{empty_str}| {x+1}/{max_val}",
            end=""
            )
        yield

        # If you can’t guarantee that the new
        # line of text is not shorter than the existing line
        # then you just need to add a “clear
        # to end of line” escape sequence, '\x1b[1K' ('\x1b' = ESC):
        print('\x1b[1K\r', end='')

    final_val, final_remain = divmod(max_val, len(blocklist))
    remain = 1 if final_remain else 0
    fb_str = (final_val + remain) * '█'
    print(
        f"100%|{fb_str}| {max_val}/{max_val}",
        end=""
        )
