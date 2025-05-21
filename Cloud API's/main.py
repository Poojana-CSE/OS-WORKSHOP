# Clous API's (Google Maps, Twitter APIs): Handle millions of requests by using thread pools, async I/O, and rate limiting to avoid thread exhaustion and latency spikes

import concurrent.futures
import time
import threading
refill_tokens = 4

def rate_limit(user_id):
    global request_tokens
    with lock():
        if(request_tokens > 0):
            print(user_id, "Request Processed")
            time.sleep(0, 2)
        else:
            print(user_id, "Request Not Processed")


def refill_tokens():
    global request_tokens
    while(True):
        time.sleep(1)
        with lock:
            request_tokens = 5


threading.Thread(target = refill_tokens, True).start()
with concurrent.futures.ThreadPoolExecutor(max_workers=10):
    for i in range(15):
        executor.submit(rate_limit,"user"+i)