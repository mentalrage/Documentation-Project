*** UID:000013 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Browser

## Status

- Confidence: strong for subsystem placement, medium for exact original class/file split
- Likely source module: [UID:0000HV][Browser](by-file/Browser.md)
- Current file: `class_Browser.cpp`
- Current range: `0x0046f480-0x00471067`
- Evidence basis: `simroot_v2\class_Browser.meta_wave3`, Wave2 `Browser.json`, generated source, browser subsystem cross-references, and targeted IDA MCP checks.

## Responsibility

`Browser` is a COM-style embedded browser object/event sink used by the older browser-control path. Wave2 notes say it implements IUnknown, IOleClientSite, IOleInPlaceSite, IDocHostUIHandler, and IDispatch, and uses an advisory connection for browser events. Its methods handle QueryInterface, unimplemented COM slots, dispatch events, connection cleanup, and browser teardown.

## Methods

Active methods:

- `0x0046f480` `~Browser`
- `0x0046f540` `QueryInterface`
- `0x0046f7e0` `QueryService_NotImpl`
- `0x0046f7f0` `QueryStatus_NotImpl`
- `0x0046f800` `TranslateAccelerator_NotImpl`
- `0x0046f810` `Invoke`
- `0x00470330` `ScalarDeletingDestructor`

Disabled/adjustor-like methods:

- `0x00470fdc`
- `0x00470fe6`
- `0x00470ff0`
- `0x00470ffa`
- `0x0047105e`

## Ownership Notes

- `Browser::~Browser` and `ScalarDeletingDestructor` call `UnadviseConnectionPoint`, release COM interfaces, destroy hosted windows, and clear URL/string state.
- `Browser::Invoke` handles browser event dispatch IDs such as download begin/complete, navigation, and new-window cases.
- This class should stay with `BrowserWindow`, `BrowserThread`, `BrowserControlPaneOld`, `browser__Notification`, and the COM helper globals in the browser module.
- The shared COM event id and IID evidence is tracked in [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md) and [UID:0000T2][IID_BrowserEventSink](by-global/IID_BrowserEventSink.md).

## IDA Evidence

- IDA MCP confirms `~Browser` at `0x0046f480-0x0046f53e`.
- IDA MCP confirms `QueryInterface` at `0x0046f540-0x0046f66f`.
- IDA MCP confirms `ScalarDeletingDestructor` at `0x00470330-0x00470406`.
- IDA MCP shows `UnadviseConnectionPoint` at `0x00470980` is called from both `~Browser` and scalar deletion cleanup paths.
- IDA MCP shows `QueryInterface` uses [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md) for 16-byte COM GUID/IID comparisons.

## Open Questions

- The current `ScalarDeletingDestructor` naming is still compiler-artifact flavored and should eventually become a normal destructor/delete wrapper representation.
- The exact multiple-inheritance/interface declaration needs class-layout work before final header placement.
- Confirm whether modern and old browser classes coexisted in one file or were separate `.cpp` files in the original project.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md)
- [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md)
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- What existed before: the page documented the COM/browser responsibility, major methods, ownership notes, and IDA evidence, but completion/confidence metadata remained `0/0`.
- What it was changed to: scores were set to `72/78`.
- Summary and evidence: destructor, QueryInterface, Invoke, scalar delete, GUID helper, and vtable/string references make the class identity strong; exact multiple-inheritance layout and final old/new browser source split still need deeper reconstruction.
