** TARGET-REPORT-UID:000218 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000218 InlineIsEqualGUID / Browser GUID Compare Helper Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:000218] from a Browser-authored free helper named `BrowserGuidCompareHelper` to the Windows SDK `guiddef.h` inline GUID predicate `InlineIsEqualGUID` emitted from Browser `QueryInterface` source-use contexts.
- Final disposition: no split is needed; rename/reword the page, mark it non-emitting external SDK/header-inline helper evidence, and keep Browser `QueryInterface` callers responsible for source-level `InlineIsEqualGUID` / `IsEqualGUID` / `IsEqualIID` use.
- Required action: supervisor should update the target page, by-memory coverage row, by-memory ignored ledger, Browser file helper table, and stale `DIID_DWebBrowserEvents2` support wording. B002 did not edit by-* docs.
- Confidence: very strong for bytes, range, caller set, helper semantics, Browser source-use context, and SDK-inline identity; below final-audit only because live IDA MCP was unavailable today and no original 2000s SDK header/PDB is present.

## Supporting Research

## Target

- Target UID: `000218`
- Target path: `by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md`
- Source queue/report row: supervisor assignment `B002-goal2-browser-guid-compare-helper-source-quality-000218-20260617`
- Current supervisor classification: report-only B-agent research target; no direct by-* edits authorized unless a split is objectively required.
- Current scores and parent state: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`, C++ block blank.
- Current generated state: `auto-generated/-ag-memory-coverage.md` routes [UID:000218] to `auto-generated/NexusTK/browser/Browser.cpp` but marks generated code present as `no`; the validator-generated Browser.cpp currently contains only [UID:0001OD] browser alert strings, not this helper.

## Executive Recommendation

The best source-facing helper name is `InlineIsEqualGUID`, with `IsEqualGUID` or `IsEqualIID` used at source call sites depending on whether the source is comparing generic GUIDs or IIDs. The observed body is source-equivalent to the local Windows Kits `guiddef.h` `InlineIsEqualGUID(REFGUID rguid1, REFGUID rguid2)` inline function: four `unsigned long` comparisons and an `int` return. The helper should not be presented as a Browser-owned private helper, and `IsEqualGuid16` should be treated only as a generated descriptive name from `simroot_v2`.

Recommended after-state for [UID:000218]:

- `COMPLETION:90`
- `CONFIDENCE:94`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTION_CPP CODE:` blank
- Recommended filename/title: `by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md`
- Coverage handling: `ignored`, external Windows SDK/header-inline helper emitted from Browser source use.

This target currently clears the active combined-score/emitter code-entry gate only under its existing `RECONSTRUCTABLE:TRUE`/Browser-emitter classification. Reanalysis shows that classification is the wrong source shape. The active gate replaces the stale `95/95` wording, but it is a minimum eligibility rule, not permission to inject a project-local helper when the evidence points to an SDK inline dependency. The formal `RECONSTRUCTION_CPP CODE` block should not be populated.

## Supervisor Active Recheck

- The supervisor specifically required reanalysis of all existing claims, source-facing helper name, argument style, return type, GUID declaration policy, Browser/BrowserWindow/BrowserControlPane `QueryInterface` boundaries, Browser GUID data/global relationship, active code-gate wording, callers/xrefs, adjacent boundaries, generated Browser.cpp output, Browser docs, BrowserControlPane/BrowserWindow docs, global `DIID_DWebBrowserEvents2` neighborhood, and IDA/PE evidence.
- The assigned item does not require split repair. The function body is exact at `0x004710e0-0x0047110e`, with `0xcc` padding before and after. No mixed subrange exists inside the helper.
- All source-bearing behavior in scope is accounted for by the single helper body and its five direct callers. The real correction is source classification and naming, not range splitting.

## Inference Research Guidance Check

`by-structure.md` changed the code-entry rule to: `RECONSTRUCTABLE:TRUE`, confirmed nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`. It also says this is only minimum eligibility and source shape/dependencies must still support final code. The target page still says C++ is withheld because of a `95%`/`95/95` final-code gate. That is stale.

`inference_research.md` cautions that nearby Browser consumers do not by themselves prove source ownership. Applying that guidance here changes the conclusion: the five Browser-family direct callers prove Browser source-use context, but the helper body and local SDK header prove a stronger external-header-inline source identity.

Evidence classification:

- Direct PE facts: local byte extraction from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`.
- Documentation evidence: existing IDA-backed Browser, BrowserWindow, BrowserControlPane, Browser, BrowserThread, GUID data, and coverage pages.
- Inference: original source likely called `InlineIsEqualGUID`, `IsEqualGUID`, or `IsEqualIID` from Windows headers in Browser `QueryInterface` code; exact macro spelling cannot be proven without original source/PDB, but a project-local Browser helper is now the weaker explanation.

## Heuristic / Inference Reanalysis And Validation

### Placeholder / Generated Name `sub_4710E0`

- Existing claim: target page calls the current IDA name `sub_4710E0` and keeps the helper name provisional.
- Evidence checked: PE byte range, direct call scan, project-level resolved/unresolved reports, target prose, Browser file helper table, and `simroot_v2/browser/Browser.cpp`.
- Best inference: replace source-facing name with `InlineIsEqualGUID`; keep `BrowserGuidCompareHelper` only as a retired descriptive page name if a rename is not immediately applied.
- Rejected alternatives:
  - `sub_4710E0`: stripped/generated placeholder, not source-facing.
  - `BrowserGuidCompareHelper`: useful descriptive name, but falsely implies Browser-authored helper ownership.
  - `IsEqualGuid16`: generated `simroot_v2` name, behaviorally accurate but nonstandard and not original-proof.
  - `BrowserCompareGuid` or similar: no evidence for a Browser-local symbol.
- Remaining issue: exact original call spelling may have been `InlineIsEqualGUID`, `IsEqualGUID` under `__INLINE_ISEQUAL_GUID`, or `IsEqualIID` wrapping the same helper. This does not block classification; it only keeps confidence under `95`.

### Helper Behavior, Argument Style, And Return Type

- Existing claim: two pointers to 16-byte GUID/IID values, returns `1` or `0`.
- PE validation: target bytes are `55 8b ec 8b 55 08 8b 45 0c 56 be 0c 00 00 00 90 8b 0a 3b 08 75 13 83 c2 04 83 c0 04 83 ee 04 73 ef b8 01 00 00 00 5e 5d c3 33 c0 5e 5d c3`.
- Callsite validation: callers push the constant GUID first and the requested IID pointer second; the callee sees the requested IID as argument 0 and the constant as argument 1.
- Best source-facing style: `int InlineIsEqualGUID(REFGUID rguid1, REFGUID rguid2)` from `guiddef.h`; caller code should pass references, for example `InlineIsEqualGUID(*riid, IID_IDocHostUIHandler)` or equivalent `IsEqualIID(*riid, IID_IDocHostUIHandler)`.
- Acceptable descriptive fallback only if no SDK/header route is available: `static int IsEqualGuid16(const GUID *lhs, const GUID *rhs)`. This should not be the final recommendation because it invents a local helper.
- Rejected return types:
  - `bool`: semantically fine for `if` use, but the SDK helper returns `int` and the body writes full `eax = 1` or `eax = 0`.
  - `BOOL`: plausible Windows style, but the actual local SDK declaration uses `int`.
  - `HRESULT`: wrong; callers test truth, not COM status.

### SDK/Header Inline Identity

- Evidence checked: local Windows Kits header `C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\shared\guiddef.h`.
- Header evidence: `InlineIsEqualGUID(REFGUID rguid1, REFGUID rguid2)` returns an `int` computed by comparing `((unsigned long *)&rguid1)[0..3]` against `((unsigned long *)&rguid2)[0..3]`. `IsEqualIID`, `IsEqualCLSID`, and `IsEqualGUID` macros/functions wrap the same GUID equality concept.
- Inference: while the local header is modern, the expression is the long-standing Windows GUID equality idiom and matches the binary body too closely to keep a Browser-authored helper as the primary inference.
- Rejected alternative: a handwritten Browser-specific helper that happens to duplicate `guiddef.h` exactly. It is possible but lower probability because all callers are COM `QueryInterface` checks and no Browser-specific policy is present.

### GUID Declaration Policy

- Existing target claim: broad [UID:000272] `BrowserComGuidReadOnlyData` is tied to Browser data and final GUID declaration policy remains unresolved.
- Current support-doc state: [UID:000272] has since been corrected to a non-emitting mixed map. The exact Browser-owned child is [UID:0003OH] `0x00631580-0x00631660.BrowserComGuidConstants`, which is `89/92`, reconstructable, Browser-owned, and lists standard GUIDs from `IID_IUnknown` through `IID_IHTMLDocument2`.
- Best policy: use Windows/OLE/MSHTML SDK declarations for standard GUIDs whenever available. Do not emit raw GUID byte arrays from [UID:000218]. `DIID_DWebBrowserEvents2` remains Browser source-use data, but it is a standard WebBrowser event IID and belongs in the GUID child/global policy, not in the helper.
- Fallback policy if the final build SDK lacks an old browser/MSHTML symbol: declare missing GUIDs once in Browser COM compatibility declarations, preferably with `DEFINE_GUID`/`EXTERN_C const IID` style, not as local arrays and not in the helper page.
- Rejected alternatives:
  - raw `static const GUID k...` arrays inside [UID:000218] formal code: outside this memory range and duplicates GUID pages.
  - keeping the whole [UID:000272] aggregate Browser-owned/reconstructable: contradicted by its DirectDraw, libjpeg, zlib, and runtime boundaries.

### Browser / BrowserWindow / BrowserControlPane `QueryInterface` Boundaries

- BrowserWindow calls [UID:000218] at `0x0046a04f` and `0x0046a069`, after pushing `0x00631630` and `0x00631640`; these are `IID_IDocHostUIHandler` and `IID_IDocHostShowUI` per [UID:0003OH].
- BrowserControlPane calls [UID:000218] at `0x0046c760` and `0x0046c777`, also for `IID_IDocHostUIHandler` and `IID_IDocHostShowUI`.
- Browser calls [UID:000218] at `0x0046f636`, after pushing `0x006315b0`, which [UID:0003OH] identifies as `IID_IOleWindow`.
- Ownership boundary: the three `QueryInterface` bodies remain owned by their classes (`BrowserWindow`, `BrowserControlPane`, `Browser`). The helper is shared external-header inline code emitted because those Browser source units use GUID equality. Consumer xrefs prove Browser source-use, not Browser-authored ownership.
- Rejected alternatives:
  - attach helper to `BrowserWindow`: ignores BrowserControlPane and Browser callers.
  - attach helper to `BrowserControlPane`: ignores BrowserWindow and Browser callers.
  - attach helper to `Browser` class: ignores new host/control callers and overfits the legacy object.
  - attach helper to `DIID_DWebBrowserEvents2`: the helper compares several GUIDs and has no global-data ownership.

### Active Code Gate And Formal C++ Readiness

- Current target average: `(82 + 90) / 2 = 86`, so the old metadata technically clears the active combined-score/emitter gate.
- Reanalysis result: the target should no longer be `RECONSTRUCTABLE:TRUE` with a Browser emitter. Once corrected to `RECONSTRUCTABLE:FALSE`, the code-entry gate no longer applies.
- Even if the supervisor keeps `RECONSTRUCTABLE:TRUE`, the formal block should remain blank for concrete source-shape reasons:
  - the source body is an SDK inline helper, not Browser-authored code;
  - inserting `InlineIsEqualGUID` into `Browser.cpp` risks duplicate-definition/conflict with `guiddef.h`;
  - inserting `IsEqualGuid16` or `BrowserGuidCompareHelper` would bake in a generated/descriptive name;
  - GUID declaration policy belongs to [UID:0003OH]/[UID:0000T2] and caller pages, not this helper page.

### Historical Assumptions Rechecked

- Historical assumption: `BrowserComGuidReadOnlyData` is a Browser-owned reconstructable aggregate. Rejected. It is now a mixed non-emitting map; exact Browser GUID child is [UID:0003OH].
- Historical assumption: blank C++ is justified by `95/95` gate. Rejected. Current policy is the combined-score/emitter gate, but source-shape still blocks this helper.
- Historical assumption: `BrowserGuidCompareHelper` is an adequate final name. Rejected as final source-facing name; it remains acceptable only as a descriptive alias.
- Historical assumption: unresolved helper/GUID names block all conclusions. Rejected. Standard GUID identities and SDK helper identity now provide a high-probability source route.

## Evidence Standards Used

- Live IDA MCP was retried three times against `http://127.0.0.1:13337/mcp` and failed with `Unable to connect to the remote server`. No new live IDA claims are made in this report.
- Existing IDA-backed docs were used as documentation evidence where they record prior live MCP function/xref/decompile checks.
- Independent PE evidence was collected from the local executable to confirm bytes, padding, image base, MD5, and five direct `CALL` references.
- Local SDK header evidence was used only for `guiddef.h` helper naming/signature/body. It is not treated as proof of the exact original SDK version.

## IDA / PE Facts

- PE path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- PE MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- Section count: 4
- Target file offset: `0x704e0`
- Target range bytes: `55 8b ec 8b 55 08 8b 45 0c 56 be 0c 00 00 00 90 8b 0a 3b 08 75 13 83 c2 04 83 c0 04 83 ee 04 73 ef b8 01 00 00 00 5e 5d c3 33 c0 5e 5d c3`
- Padding before: `0x004710df = 0xcc`
- Padding after: `0x0047110e = 0xcc`, `0x0047110f = 0xcc`
- Direct PE `CALL` count to `0x004710e0`: 5

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004710df-0x004710e0` | [UID:0000VN] `by-memory/-ignored.md` | one-byte padding | false | none | ignored | unchanged |
| `0x004710e0-0x0047110e` | [UID:000218] target | `InlineIsEqualGUID` SDK/header-inline helper | recommended false | recommended none | after `90/94` | rename/reclassify |
| `0x0047110e-0x00471110` | [UID:0000VN] `by-memory/-ignored.md` | two-byte padding | false | none | ignored | unchanged |
| `0x00471110-0x00471141` | [UID:000219] `CrtWideVsnprintfWrapper` | CRT helper wrapper | false | none | ignored | successor boundary |
| `0x00631580-0x00631660` | [UID:0003OH] `BrowserComGuidConstants` | exact Browser COM GUID child | true | [UID:0000HV] | `89/92` | GUID declaration/use context |
| `0x00631570-0x00632560` | [UID:000272] `BrowserComGuidReadOnlyData` | mixed DirectDraw/Browser/libjpeg/zlib map | false | none | `88/92` | broad aggregate no longer Browser-owned |
| `0x00631610` | [UID:0000T2] `DIID_DWebBrowserEvents2` | standard event IID global/source-use | true | [UID:0000HV] | `88/92` | support wording needs stale aggregate correction |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0046a04f` | `CALL 0x004710e0`, bytes `e8 8c 70 00 00` | BrowserWindow `QueryInterface`, compares requested IID to `IID_IDocHostUIHandler` at `0x00631630`. |
| `0x0046a069` | `CALL 0x004710e0`, bytes `e8 72 70 00 00` | BrowserWindow `QueryInterface`, compares requested IID to `IID_IDocHostShowUI` at `0x00631640`. |
| `0x0046c760` | `CALL 0x004710e0`, bytes `e8 7b 49 00 00` | BrowserControlPane `QueryInterface`, compares requested IID to `IID_IDocHostUIHandler`. |
| `0x0046c777` | `CALL 0x004710e0`, bytes `e8 64 49 00 00` | BrowserControlPane `QueryInterface`, compares requested IID to `IID_IDocHostShowUI`. |
| `0x0046f636` | `CALL 0x004710e0`, bytes `e8 a5 1a 00 00` | Browser `QueryInterface`, compares requested IID to `IID_IOleWindow` at `0x006315b0`. |

## Documentation Evidence And IDA Status

- Target page supports exact behavior/range/callers but is stale on source name, GUID data relationship, `95/95` code-gate wording, and Browser-authored helper classification.
- [UID:0000HV] `by-file/Browser.md` still lists this as a "Free Helper That Should Move Into This Module" and says active Browser output has unresolved `sub_4710E0`. That should be corrected because the helper is an SDK inline source-use artifact, not a Browser-authored free helper.
- [UID:0003OH] exact Browser COM GUID child resolves the GUID values and should replace target prose that relies on the broad [UID:000272] aggregate for Browser GUID ownership.
- [UID:0000T2] `DIID_DWebBrowserEvents2.md` is partly stale because it says [UID:000272] is reconstructable and attached to Browser; [UID:000272] is now `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and delegates Browser GUIDs to [UID:0003OH].
- `project-level/-unresolved.md` still lists `sub_4710E0` because the target page preserves raw placeholder mentions. The target page should remove or demote those to non-source historical evidence in a way that does not present `sub_4710E0` as unresolved source naming.
- `simroot_v2/browser/Browser.cpp` already has a generated `bool IsEqualGuid16(const GUID *lhs, const GUID *rhs)` helper, but this is not authoritative. It is useful only as evidence that generated output recognized a GUID predicate and did not recover the SDK name.
- `project-documentation/auto-generated/NexusTK/browser/Browser.cpp` has no code for [UID:000218] because the target C++ block is blank.

## Ranked Ownership Analysis

### 1. Windows SDK `guiddef.h` inline helper, source-used by Browser `QueryInterface` code

- Evidence for: target body matches local `guiddef.h` `InlineIsEqualGUID` four-dword body; return type and argument style match `int` plus `REFGUID`; all five direct callers are COM `QueryInterface` GUID comparisons; no Browser-specific state or policy exists inside the helper.
- Evidence against: no original PDB or 2000s SDK header is available; the exact source spelling could have been `InlineIsEqualGUID`, `IsEqualGUID` under macro remapping, or `IsEqualIID`.
- Decision: accepted. This is the strongest source-facing explanation. Metadata should represent it as non-emitting external SDK/header-inline evidence with Browser source-use callers.

### 2. [UID:0000HV] Browser file as Browser-authored free helper

- Evidence for: all direct callers are in Browser-family `QueryInterface` code, and the current emitter route reaches `auto-generated/NexusTK/browser/Browser.cpp`.
- Evidence against: consumer xrefs are not ownership proof; local SDK helper body/name/signature is a better explanation; Browser-specific helper names are not supported; emitting a Browser-local helper would risk duplicate definitions or bake in a generated name.
- Decision: reject as canonical source ownership. Keep Browser only as the source-use context for callers.

### 3. `BrowserWindow`, `BrowserControlPane`, or `Browser` class ownership

- Evidence for: each class has at least one direct call from its `QueryInterface` body.
- Evidence against: calls are shared across three class contexts; helper has no `this`, no class state, and no class-specific behavior.
- Decision: reject direct class ownership. The class pages own their `QueryInterface` methods only.

### 4. [UID:0003OH] Browser COM GUID constants or [UID:0000T2] `DIID_DWebBrowserEvents2`

- Evidence for: helper compares values from the Browser GUID band, and `DIID_DWebBrowserEvents2` is one standard GUID in the same source-use neighborhood.
- Evidence against: the helper has code behavior, not data ownership; it compares multiple GUIDs, including `IID_IDocHostUIHandler`, `IID_IDocHostShowUI`, and `IID_IOleWindow`, not only the event DIID.
- Decision: reject as owner. These pages own/route GUID declarations and policy, not the equality helper.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: no new NexusTK source file is needed for [UID:000218]. Browser source/header should include the relevant Windows/OLE/MSHTML headers or a narrow compatibility GUID declaration block for missing SDK constants.
- Candidate related items that belong: none as a new source file. Existing related pages are [UID:0003OH], [UID:0000T2], BrowserWindow/BrowserControlPane/Browser `QueryInterface` pages, and Browser source root [UID:0000HV].
- Candidate related items rejected: broad [UID:000272] mixed map, [UID:0001OB] mixed vtable/string index, and class-specific ownership routes.
- Standalone, narrow, or broad source-file inference: no standalone file. This is an external header-inline artifact used in Browser source.

## Negative Evidence Summary

- No PE/body evidence shows Browser-specific logic, state, fields, globals, or side effects in the helper.
- No caller outside Browser was found by the PE direct-call scan, but that proves only source-use locality, not authorship.
- No evidence supports a mutable `GUID *` parameter style. Callers pass constants and requested IID pointers.
- No evidence supports local raw GUID declarations inside the helper. GUID constants are separate data/source declaration policy.
- No split evidence exists inside `0x004710e0-0x0047110e`; all bytes decode as one helper.
- No final-output source should use `sub_4710E0`, `FUN_004710e0`, or `BrowserGuidCompareHelper` as a function name.

## First-Draft C++ Recommendation

Do not populate [UID:000218]'s formal `RECONSTRUCTION_CPP CODE` block.

The source-equivalent SDK helper body is:

```cpp
// Source dependency, not a Browser.cpp-owned helper:
// guiddef.h provides InlineIsEqualGUID(REFGUID, REFGUID) and IsEqualIID/IsEqualGUID wrappers.
```

Caller source should express the behavior at the `QueryInterface` sites instead:

```cpp
if (InlineIsEqualGUID(*riid, IID_IDocHostUIHandler)) {
    // return the IDocHostUIHandler interface view
}

if (InlineIsEqualGUID(*riid, IID_IDocHostShowUI)) {
    // return the IDocHostShowUI interface view
}
```

`IsEqualIID(*riid, IID_...)` is also source-natural for IID comparisons if the final header/macro setup maps to the same inline path. The formal block should stay blank because a standalone helper definition in Browser.cpp would either duplicate SDK `guiddef.h` or introduce a non-original local name.

## Exact Recommended By-Doc Changes

### Target Page

Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004710e0-0x0047110e.BrowserGuidCompareHelper.md`

Recommended rename:

```text
by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md
```

Recommended metadata after rename:

```text
*** UID:000218 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended replacement title:

```text
# 0x004710e0-0x0047110e InlineIsEqualGUID
```

Recommended replacement for the target `Reconstruction Notes` section:

```text
## Reconstruction Notes

This body is source-equivalent to the Windows SDK `guiddef.h` inline helper `InlineIsEqualGUID(REFGUID, REFGUID)`: it compares a GUID as four `unsigned long` values and returns `1` for equality or `0` for mismatch. BrowserWindow, BrowserControlPane, and Browser `QueryInterface` methods are the source-use sites, but the helper itself should come from Windows SDK header declarations rather than a Browser-owned private function.

Do not populate this page's formal C++ block. The active code-entry policy is the combined-score/emitter gate from `by-structure.md`, not the old `95/95` gate, but this item should be non-emitting after source-shape reanalysis. Final caller code should use `InlineIsEqualGUID`, `IsEqualGUID`, or `IsEqualIID` from the SDK/header policy, and GUID declarations should be handled by [UID:0003OH] and [UID:0000T2], not by this helper page.
```

### by-memory Coverage Row

Supervisor-owned path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md`

Replace the current [UID:000218] row under the `0x004710df-0x00471110` neighborhood with:

```text
    - [UID:000218][0x004710e0-0x0047110e.InlineIsEqualGUID](by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md) 0x004710e0-0x0047110e | SDK inline helper | InlineIsEqualGUID : ignored : 90% : very-strong : PE bytes and five direct call sites confirm the exact 0x2e-byte GUID equality helper; local Windows Kits `guiddef.h` matches the four-dword `InlineIsEqualGUID(REFGUID, REFGUID)` body and `int` return; BrowserWindow, BrowserControlPane, and Browser `QueryInterface` are source-use callers, but the helper should be regenerated from Windows SDK/header use rather than emitted as a Browser-owned private helper.
```

### by-memory Ignored Ledger

Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-ignored.md`

Add after the `0x004710df-0x004710e0` padding entry and before the `0x0047110e-0x00471110` padding entry:

```text
- `0x004710e0-0x0047110e` - Windows SDK `InlineIsEqualGUID` header-inline GUID equality helper.
  - Classification: ignored external SDK/header-inline helper emitted from Browser COM `QueryInterface` source use, not NexusTK-authored product logic.
  - Evidence: local PE bytes for MD5 `4247e04e20b65d6414c7238aa8ff5515` match the four-dword GUID equality loop; PE direct-call scan finds exactly five calls at `0x0046a04f`, `0x0046a069`, `0x0046c760`, `0x0046c777`, and `0x0046f636`; local Windows Kits `guiddef.h` defines `InlineIsEqualGUID(REFGUID, REFGUID)` with the same four `unsigned long` comparisons and `int` return.
  - Replacement source-use: BrowserWindow, BrowserControlPane, and Browser `QueryInterface` source should call SDK `InlineIsEqualGUID` / `IsEqualGUID` / `IsEqualIID`; [UID:0003OH] and [UID:0000T2] own the GUID declaration policy.
```

### Browser File Helper Table

Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-file\Browser.md`

In section `## Free Helpers That Should Move Into This Module`, remove the [UID:000218] row from the free-helper table. Add this subsection immediately after the free-helper table:

```text
### External/Header Inline Helpers Used By This Module

| Function | Range | Source-use context | Reason |
| --- | --- | --- | --- |
| [UID:000218][0x004710e0-0x0047110e.InlineIsEqualGUID](by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md) | `0x004710e0-0x0047110e` | BrowserWindow, BrowserControlPane, and Browser `QueryInterface` callers | Source-equivalent to Windows SDK `guiddef.h` `InlineIsEqualGUID(REFGUID, REFGUID)`; keep Browser as the source-use module for the caller methods, but do not migrate this as a Browser-authored private helper. |
```

### DIID_DWebBrowserEvents2 Support Wording

Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-global\DIID_DWebBrowserEvents2.md`

Replace the current `Containing data range` status bullet:

```text
- Containing data range: [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md)
```

with:

```text
- Containing data range: exact Browser GUID child [UID:0003OH][0x00631580-0x00631660.BrowserComGuidConstants](by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md), inside mixed non-emitting map [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md)
```

Replace the `Reconstruction Evidence` bullet that currently says [UID:000272] is reconstructable/attached:

```text
- [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md) covers the surrounding browser/OLE GUID and COM interface-map data, is reconstructable, and is attached to [UID:0000HV][Browser](by-file/Browser.md).
```

with:

```text
- [UID:0003OH][0x00631580-0x00631660.BrowserComGuidConstants](by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md) is the exact reconstructable Browser-owned GUID band. The broader [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md) is now a non-emitting mixed map that also covers DirectDraw, libjpeg, zlib, and runtime-adjacent data.
```

Replace the follow-up bullet:

```text
- Continue naming interface-map records after the primary GUID band in [UID:000272][0x00631570-0x00632560.BrowserComGuidReadOnlyData](by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md).
```

with:

```text
- Continue final COM declaration policy against exact Browser GUID child [UID:0003OH] and caller/source pages; do not treat the broad [UID:000272] mixed map as a Browser-owned declaration block.
```

## Final Recommendation

- Exact changes applied: only this B002 research report was created.
- Exact parent assignments recommended: set [UID:000218] `CANONICAL_OWNER:NONE`; do not assign it to BrowserWindow, BrowserControlPane, Browser, Browser file, or GUID globals as a source-authored item.
- Exact emitter recommendation: clear `EMITTER_UIDS`; do not emit standalone C++ for this page.
- Exact reconstructable recommendation: set `RECONSTRUCTABLE:FALSE` because this is external Windows SDK/header-inline helper code, not NexusTK product source logic. Browser caller source remains reconstructable on its own pages.
- Exact C++ recommendation: leave formal block blank; use `InlineIsEqualGUID` / `IsEqualGUID` / `IsEqualIID` in caller methods and SDK/header GUID declarations in the Browser COM source/header pass.
- Exact future work outside this assignment: update caller `QueryInterface` source drafts when those pages receive final C++; ensure `Browser.cpp` includes the required OLE/MSHTML headers or compatibility GUID declarations.

## Follow-Up Actions

- Supervisor actions: apply the target rename/metadata/text changes, by-memory coverage row replacement, by-memory ignored ledger entry, Browser file helper-table correction, and `DIID_DWebBrowserEvents2` support wording correction. Then run the validator on changed pages and refresh generated reports as appropriate.
- A-agent actions: when reconstructing BrowserWindow, BrowserControlPane, and Browser `QueryInterface`, call SDK GUID equality helpers instead of a local `BrowserGuidCompareHelper` or `IsEqualGuid16`.
- B002 future research actions: none required for this target unless the supervisor wants a broader browser COM declaration/header policy pass.

## Confidence

- Recommendation confidence: very strong (`94`) that this is SDK `InlineIsEqualGUID` or equivalent `IsEqualGUID`/`IsEqualIID` inline source-use, not a Browser-authored helper.
- Score confidence: `90/94` recommended. Completion is below `95` because live IDA was unavailable and the exact original SDK/macro spelling is not proven. Confidence is below `95` for the same reason.
- Remaining uncertainty: original source spelling may have been `InlineIsEqualGUID`, `IsEqualGUID` under `__INLINE_ISEQUAL_GUID`, or `IsEqualIID`; this affects caller-source style but not ownership/reconstructability recommendation.

## Validator Results

- Commands run: no validator command was run because B002 did not edit by-* docs and this report is not validator-managed project documentation.
- IDA MCP status: attempted documented endpoint `http://127.0.0.1:13337/mcp` three times; all attempts failed with `Unable to connect to the remote server`.
- Local validation: report file was created under the assigned Agent-B002 research folder only.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\000218-InlineIsEqualGUID.md`
- Modified: none outside Agent-B002 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/000218-InlineIsEqualGUID.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"000218"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
