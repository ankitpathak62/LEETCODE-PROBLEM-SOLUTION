class TimeLimitedCache {
  constructor() {
    this.store = {};
  }

  set(key, value, duration) {
    const now = new Date().getTime();
    const expirationTime = now + duration;
    if (this.store.hasOwnProperty(key) && this.store[key].expirationTime >= now) {
      this.store[key].value = value;
      this.store[key].expirationTime = expirationTime;
      return true; // return true if key exists and value and duration are updated
    } else {
      this.store[key] = { value, expirationTime };
      return false; // return false if key doesn't exist and a new key-value pair is added
    }
  }

  get(key) {
    const now = new Date().getTime();
    const cachedValue = this.store[key];
    if (cachedValue && cachedValue.expirationTime >= now) {
      return cachedValue.value; // return cached value if it exists and hasn't expired
    } else {
      delete this.store[key]; // remove expired or non-existent value from cache
      return -1; // return -1 to indicate cache miss
    }
  }

  count() {
    let count = 0;
    const now = new Date().getTime();
    for (const key in this.store) {
      const cachedValue = this.store[key];
      if (cachedValue && cachedValue.expirationTime >= now) {
        count++; // increment count for each un-expired key
      } else {
        delete this.store[key]; // remove expired or non-existent value from cache
      }
    }
    return count;
  }
}