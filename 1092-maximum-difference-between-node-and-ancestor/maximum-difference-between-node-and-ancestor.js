var maxAncestorDiff = function (r) {
  const dfs = (r, minTillNow, maxTillNow) => {
    if (r === null) return Math.max(maxTillNow - minTillNow)
    minTillNow = Math.min(minTillNow, r.val)
    maxTillNow = Math.max(maxTillNow, r.val)
    return Math.max(
      dfs(r.left, minTillNow, maxTillNow),
      dfs(r.right, minTillNow, maxTillNow)
    )
  }
  return dfs(r, Infinity, -Infinity)
}