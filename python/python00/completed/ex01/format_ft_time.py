import datetime as dt

now = dt.datetime.now()
# epoch is 1970 1 1 WOWW

# delta = dt.datetime.now() - dt.datetime(1970,1,1)
# out = now.total_second()

# timestamp gets POSIX timestamp
# POSIX timestamp is the time since the epoch
out = now.timestamp()

print(f"Seconds since January 1, 1970: \
{out:,.4f} or {out:.2e} in scientific notation")
print(now.strftime("%b %d %Y"))
