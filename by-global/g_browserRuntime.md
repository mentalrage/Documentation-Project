*** UID:0000PU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_browserRuntime

## Status

- Disposition: ignored as a standalone global; alias of [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md).
- Confidence: strong that browser dispatch fallback reads canonical `g_pScreenPane` storage; not a separate browser-owned global.
- IDA storage: [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md), the canonical [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) storage.
- Proposed owner: [UID:0000NB][ScreenPane](by-file/ScreenPane.md); browser is a consumer through an alias.

## Observed Evidence

`BrowserControlPane::HandleBrowserDispatchEvent` uses `g_browserRuntime` only in the default dispatch-id case. IDA decompilation resolves that use to `dword_67A7CC`, the same storage documented as [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md). The dispatch fallback clears byte offset `+0x5b2`, calls a virtual/callback slot at `+0x20`, and returns `DISP_E_MEMBERNOTFOUND` (`2147352573`).

IDA xrefs around this storage are broad and include cursor/runtime/UI uses outside browser. Current aliases also name related storage as `dword_67A7CC`, `g_browserStatusTextPane`, and `g_pCursorManager` in different contexts.

2026-05-26 IDA `py_eval` recheck confirms `0x0067a7cc` is a four-byte `.data` item named `dword_67A7CC`, initialized to zero, with 145 xrefs. It confirms `BrowserControlPane::HandleBrowserDispatchEvent` at `0x0046c960-0x0046caf0`, `ScreenPane` constructor `0x00556910-0x00556a5a`, and `ScreenPane` destructor `0x00556a60-0x00556cd4`. No IDA name contains `browserRuntime`.
2026-06-05 IDA MCP recheck confirmed broad xrefs to `0x0067a7cc`, matching canonical screen-pane storage rather than a browser-owned global.

## Ownership Hypothesis

The browser code consumes the root screen/runtime object for fallback event reset. The declaration should not be moved into `Browser.cpp`; use the canonical [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) storage and keep any browser-local name as a temporary typed view only.

## Type Hypothesis

Generated browser use implies the root screen/runtime object has at least:

```cpp
struct BrowserRuntimeLike {
    /* vtable +0x20 */ void (*ResetCallback)(BrowserRuntimeLike*, int);
    /* +0x5b2 */ unsigned char stateFlag;
};
```

This is shape evidence only, not a final structure.

## Follow-Up

- Keep `g_browserRuntime` in ignored global coverage as an alias of [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) unless later evidence proves a separate object.
- Continue reviewing `g_browserStatusTextPane` before deciding whether it is another alias over the same storage or a distinct browser/status pane pointer.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `-1/-1`. Summary/evidence: the page disposition says this is an ignored standalone global because it is an alias of canonical [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) storage, so it should be excluded from completion statistics rather than scored as an independent reconstruction target.
- 2026-06-05: Marked not reconstructable as a standalone global.
  - Reason: live IDA MCP recheck confirms the storage is canonical [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), so no separate browser-runtime declaration should be emitted from this alias page.
