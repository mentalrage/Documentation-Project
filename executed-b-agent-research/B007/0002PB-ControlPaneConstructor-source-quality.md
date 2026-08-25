** TARGET-REPORT-UID:0002PB **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B007 Source-Quality Report: [UID:0002PB] ControlPaneConstructor

Agent: B007  
Assignment: `B007-report-0002PB-control-pane-constructor-source-quality-20260626`  
Report timestamp: 2026-06-26 19:28:29 -04:00  
Revision assignment: `B007-revise-0002PB-control-pane-constructor-source-quality-20260626`  
Revision timestamp: 2026-06-26 19:35:57 -04:00  
Target: `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`  
Mode: report-only research. No leases taken. No target/support by-* docs, generated files, validator/tool state, IDA DB files, or coverage reports were edited.
Implementation callback completed: 2026-06-26. Accepted details were applied to the target/support by-* docs under short B007 leases; generated/project-level/tool-state files were not manually edited by B007.

## Current Target State

- Current by-memory header: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank optional emitter metadata, blank formal C++ block, `Nested:4`.
- Current owner/emitter route remains correct: exact source child [UID:0002PB] -> [UID:000038] `ControlPane` -> [UID:0000IG] `ControlPane` / `NexusTK/ui/core/ControlPane.cpp`.
- Current prose already records the important A-agent facts: exact function boundary, direct callees, vtable stores, optional bounds helper, packed state stores, and broad derived-control caller population.
- Remaining source-quality blockers are now resolvable at first-draft level:
  - the optional third argument is a `const RectBounds *bounds` style pointer;
  - `controlType` is an unsigned byte-style source argument, not a signed semantic enum yet;
  - packed fields are better split into the inherited range/current triplet, control flags/reserved byte, visible/active bytes, visual-state byte, and hit-test suppression byte rather than one opaque dword;
  - the fixed value `10` is the inherited normal/default visual state value used by existing SelectBox and state-helper docs, but this target should emit the literal in constructor code rather than defining a constant outside its range;
  - current active code-entry gate is met after this pass.

## MCP Session And Tool Facts

IDA MCP was available and responsive. This report is not fallback-only.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- `initialize` and `tools/list` succeeded.
- Active database: `80de0a67`.
- `idb_list`: one active worker session, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid 26892`, `is_active:true`, `is_analyzing:false`.
- `server_health(database=80de0a67)`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- First MCP body batch was retried because the current server requires `database=<session_id>` on each tool call and uses `addr` rather than old `addrs` for `decompile`/`disasm`. The endpoint was responsive; the corrected calls below succeeded.

Fresh MCP calls used:

- `lookup_funcs` for `0x004949e0`, `0x00494a81`, `0x00494a90`, `0x00494b50`, `0x00494b80`, `0x00544460`, `0x00544bd0`, `0x0041d690`, and `0x0049b170`.
- `decompile`, `disasm`, `callees`, `xrefs_to`, `get_bytes` for `0x004949e0`.
- `xrefs_to` for `0x004949e0` and the three `ControlPane` vtable bases `0x00617a90`, `0x00617af8`, `0x00617b28`.
- `decompile`, `disasm`, `callees`, and `xrefs_to` for `Pane::Pane` at `0x00544460` and `Pane::SetBounds` at `0x00544bd0`.
- `decompile`/`disasm` for representative derived constructors using the base constructor: `0x00494c80`, `0x00499c60`, `0x004fccf0`, `0x00520540`, `0x004fce80`, `0x00501660`, `0x00424300`, `0x0046b520`, `0x00499030`, and `0x00499910`.

## Documents And Prior Reports Checked

- Target: `source-3/project-documentation/by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`.
- Owner/source route: `by-class/ControlPane.md`, `by-file/ControlPane.md`.
- Base and layout support: `by-class/Pane.md`, `by-memory/0x00544460-0x00545086.PaneCore.md`, `by-type/by-struct/PaneLayout.md`.
- Rect support: `by-type/by-struct/RectBoundsLayout.md`, `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`.
- ControlPane state support: `ControlPaneSetVisualState`, visible set/clear, active set/clear, hit-test accessor/setter, vtable data/type pages, and active-frame helper reports/docs.
- Derived constructor parity: ProgressBar, Rectangle, SelectBox, ObjectImage, NumericString, StaticText, UserShapeSelect, UserFaceSelect, and executed source-quality reports for RectangleControlPaneConstructor, SelectBoxControlPane, UserShapeSelectControlPaneCore, and UserFaceSelectControlPane.
- Historical context: existing A003/A001 notes and executed B reports were treated as leads only and rechecked against current MCP where target behavior mattered.

## Live Function And Boundary Findings

`lookup_funcs(database=80de0a67)` reports:

| Query | Result |
| --- | --- |
| `0x004949e0` | modeled function `sub_4949E0`, size `0xa1`, range `0x004949e0-0x00494a81`. |
| `0x00494a81` | not a function. |
| `0x00494a90` | not a function; first progress-bar range helper is raw code-shaped bytes. |
| `0x00494b50` | modeled `sub_494B50`, the progress current-value setter boundary. |
| `0x00494b80` | modeled `sub_494B80`, the base visual-state setter. |
| `0x00544460` | modeled `sub_544460`, the `Pane` constructor. |
| `0x00544bd0` | modeled `sub_544BD0`, the inherited `Pane::SetBounds`/bounds-localization helper. |

`get_bytes` confirms:

- the target body is exactly `0xa1` bytes and ends with `retn 8`;
- `0x00494a81-0x00494a90` is fifteen `0xcc` bytes;
- `0x00494a90` begins the progress-bar range-start raw helper prologue.

No split is recommended. The target is one exact constructor body. The following progress-bar raw helpers and modeled state virtuals are siblings, not target bytes.

## Target Body Findings

Current `decompile(0x004949e0)` returns the source shape:

- receiver `this`;
- first explicit argument `char a2`, written to `this+0xfe`;
- second explicit argument `int *a3`, null-checked before the bounds helper;
- direct call to `0x00544460` with pane mode `1`;
- three `ControlPane` vptr writes to `+0x00`, `+0xa0`, and `+0xa4`;
- optional `0x00544bd0(this, bounds, 0)` call;
- state stores at `+0xff`, `+0xf8`, `+0xfc`, and `+0x103`;
- return of `this`.

Current `disasm(0x004949e0)` pins the important instructions:

| Address | Direct fact |
| --- | --- |
| `0x00494a0b` | calls `sub_544460` after pushing `1`. |
| `0x00494a13` | writes `[esi+0xfe]` from the first explicit byte argument. |
| `0x00494a23` | stores primary `ControlPane` vtable `0x00617a90`. |
| `0x00494a29` | stores secondary `ControlPane` vtable `0x00617af8` at `+0xa0`. |
| `0x00494a33` | stores tertiary `ControlPane` vtable `0x00617b28` at `+0xa4`. |
| `0x00494a3d-0x00494a46` | skips bounds call when the pointer is null; otherwise calls `0x00544bd0` with second argument `0`. |
| `0x00494a4d` | stores dword `0x00010000` at `+0xff`. |
| `0x00494a57` | stores dword zero at `+0xf8`. |
| `0x00494a5d` | stores word zero at `+0xfc`. |
| `0x00494a66` | stores word `10` at `+0x103`. |
| `0x00494a7e` | returns with `retn 8`. |

`callees(0x004949e0)` reports only `0x00544460` and `0x00544bd0` as direct callees.

`xrefs_to(0x004949e0)` reports 52 code xrefs. The caller set includes progress-bar, rectangle, select-box, text/static controls, object/image controls, browser/minimap/fitting-room controls, selector controls, and dialog factories. This confirms shared base-control infrastructure rather than a feature-dialog local helper.

`xrefs_to` for `0x00617a90`, `0x00617af8`, and `0x00617b28` reports exactly one data xref each, at `0x00494a23`, `0x00494a29`, and `0x00494a33` inside this constructor.

## Bounds Argument Resolution

`Pane::SetBounds` at `0x00544bd0` resolves the optional argument type strongly enough for first-draft C++:

- decompilation reads a 16-byte record through `a2[0..3]`;
- it initializes the pane origin at `this+0xac` from the incoming top-left fields via `InitPointPair` / `0x004b7c30`;
- it copies the full 16-byte record, offsets it by the negative origin through `OffsetRect` / `0x004b7e10`, and dispatches primary vtable slot `+0x0c` with the localized rectangle;
- docs for [UID:0001VP] `RectBoundsLayout` prove the accepted four-int `left, top, right, bottom` layout and size `16`;
- PaneCore names `0x00544bd0` as `Pane::SetBounds`.

The second helper argument is always passed as `0` by this constructor and is the inherited `SetBounds` flags/unused parameter. It should not be surfaced as a `ControlPane` constructor parameter. The source-facing constructor argument is `const RectBounds *bounds`.

## Packed Field Resolution

The constructor's compact stores should be documented as multiple logical fields, not one opaque packed integer:

| Offset | Source-facing direction | Evidence |
| --- | --- | --- |
| `+0xf8` | inherited range-start/lower-bound short, recommended base-constructor alias `m_rangeStart` | Zeroed by base constructor; ProgressBar constructor/setter docs prove this same inherited field as the progress-facing lower/min value, but that subclass use does not require the base constructor page to use the progress-specific name. |
| `+0xfa` | inherited current/range value short, recommended base-constructor alias `m_rangeCurrent` | Zeroed by the same dword at `+0xf8`; ProgressBar constructor/current-value helper consumes it as current value, while base constructor evidence only proves neutral inherited range/current state. |
| `+0xfc` | inherited range-end/upper-bound short, recommended base-constructor alias `m_rangeEnd` | Zeroed by constructor; ProgressBar constructor/setter docs prove upper/max behavior in progress controls, but no current base-only evidence proves the original base member was named as a progress max. |
| `+0xfe` | `m_controlType` byte | Written from constructor argument; derived constructors pass constants such as `8`, `22`, and `5`; fixed type-id methods are separate virtuals and should not be confused with this construction kind. |
| `+0xff` | inherited `m_controlFlags` / control flags byte | Zeroed by base default; UserShape/UserFace selector reports show derived constructors write caller control flag here. Do not name it as shape/face-specific. |
| `+0x100` | reserved inherited control-state byte | Zeroed by base default; no final consumer found in current target/support pass. Keep as reserved/descriptive until a use-site proves a stronger name. |
| `+0x101` | `m_controlVisible` / shown byte | Set to `1` by the dword `0x00010000`; state helpers set/clear this byte and invalidate; active-frame helper tests it. |
| `+0x102` | `m_controlActive` / active-focus byte | Cleared by the dword; active/deactivate helpers set/clear it and invalidate; active-frame helper tests it. |
| `+0x103` | `m_visualState` byte, normal/default value `10` | Final word write sets byte `+0x103` to `10`; `ControlPaneSetVisualState` writes this byte; SelectBox formal C++ uses its own local constant for value `10`, but no inspected support doc currently owns a shared `ControlPane` constant that [UID:0002PB] can reference without redefining. |
| `+0x104` | `m_ignoreHitTesting` / hit-test suppression byte | Final word write clears byte `+0x104`; accessor returns it and setter writes it; PopupMenu hit-test caller skips controls when it is true. |

The dword store at `+0xff` should be explained byte-wise: little-endian `0x00010000` makes `+0xff=0`, `+0x100=0`, `+0x101=1`, and `+0x102=0`. The word store at `+0x103` makes `+0x103=10` and `+0x104=0`.

Range-alias recheck: `m_minValue`, `m_currentValue`, and `m_maxValue` remain valid progress-control aliases for the inherited triplet where ProgressBar docs prove lower/current/upper semantics. They are too progress-specific for the base constructor's formal block because [UID:0002PB] only zeroes inherited state before any derived constructor installs specialized vtables or assigns derived semantics. The safer base-constructor aliases are `m_rangeStart`, `m_rangeCurrent`, and `m_rangeEnd`; this preserves the proven range/current behavior without claiming the original base source used progress-specific member names.

## Source-Form Decision

The constructor is ready for first-draft formal C++ now. It clears the active code-entry gate:

- `RECONSTRUCTABLE:TRUE`;
- nonblank `EMITTER_UIDS:000038`;
- direct owner [UID:000038] and file route [UID:0000IG] both clear source-routing gates;
- recommended average score is `(89 + 92) / 2 = 90.5`;
- current MCP evidence resolves the body, bounds type, field map, caller/callee set, vtable stores, and sibling boundary.

The first-draft C++ should express source semantics and omit compiler vptr stores, SEH/security-cookie scaffolding, raw helper names, and declarations outside the constructor's by-memory range. The prior anonymous-enum recommendation is superseded by this revision: no current support doc proves ownership of shared `kControlPaneMode` or `kControlPaneVisualStateNormal` declarations, so the target formal block must use range-safe literals `1` and `10`.

### Exact Formal `RECONSTRUCTION_CPP CODE` Recommendation

If the supervisor accepts this report, populate [UID:0002PB]'s formal block exactly with:

```cpp
ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)
    : Pane(1),
      m_rangeStart(0),
      m_rangeCurrent(0),
      m_rangeEnd(0),
      m_controlType(controlType),
      m_controlFlags(0),
      m_reservedControlState(0),
      m_controlVisible(true),
      m_controlActive(false),
      m_visualState(10),
      m_ignoreHitTesting(false)
{
    if (bounds != NULL)
        SetBounds(bounds, 0);
}
```

Implementation caveat: `m_reservedControlState` is intentionally descriptive for the zeroed `+0x100` byte. The `m_rangeStart`/`m_rangeCurrent`/`m_rangeEnd` names are intentionally neutral base-class aliases; support docs may still mention the ProgressBar-facing aliases `m_minValue`/`m_currentValue`/`m_maxValue` where those semantics are proven. If a later accepted support pass proves stronger original names before callback implementation, substitute only those field names consistently in the target/support docs and formal block. Do not downgrade to raw address or decompiler-temporary names. Do not reinsert enum or constant declarations in this by-memory formal block unless an accepted support/class page already owns those constants and the target only references them.

## Rejected Alternatives

- Leave formal C++ blank: rejected. Current evidence resolves the prior blockers enough for first-draft source C++; exact original field spellings remain confidence caps, not a blank-code proof.
- Use `char controlType`: rejected for source-facing declaration. The raw ABI is one byte, but control type values are non-negative construction kinds; `unsigned char controlType` is the safer source-facing first draft.
- Emit an anonymous enum or other constant declarations in [UID:0002PB]'s formal block: rejected by range-safety. The constructor page covers only `0x004949e0-0x00494a81`; declarations for `kControlPaneMode` or `kControlPaneVisualStateNormal` are support/class ownership candidates, not target-range code.
- Reference `kControlPaneMode` or `kControlPaneVisualStateNormal` without an accepted owning declaration: rejected. Current inspection shows only target-local or support-prose evidence for values `1` and `10`, so the formal block uses literals.
- Use progress-specific `m_minValue`/`m_currentValue`/`m_maxValue` names in the base constructor formal block: rejected for [UID:0002PB]. Keep those as ProgressBar-facing aliases in progress support pages; the base constructor recommendation uses neutral inherited range aliases.
- Use `int *bounds` or `void *bounds`: rejected. `Pane::SetBounds` and `RectBoundsLayout` prove a 16-byte `RectBounds` pointer.
- Expose the inherited `SetBounds` second argument as a constructor parameter: rejected. This constructor always passes `0`; derived constructors only pass a bounds pointer to `ControlPane`.
- Model the vtable stores in source: rejected as compiler output from constructing a polymorphic class with primary/secondary/tertiary views.
- Treat `+0xff..+0x102` as one dword field: rejected because later exact helpers and derived constructors consume individual bytes.
- Treat `+0x103` as a repeat delay: rejected for this target's formal C++ because current direct consumers support visual/control state value `10`; no timer/repeat caller was found for this byte in the ControlPane helper set.
- Move ownership to ProgressBar, ButtonControlPane, PopupMenu, MiniMap, or a dialog caller: rejected. Those are derived consumers or physical neighbors; the constructor installs base `ControlPane` vtables and is called by many unrelated reusable controls.
- Attach directly to the file [UID:0000IG] as owner: rejected as direct owner because the class [UID:000038] clears the direct-owner gate. The file remains the emitter route.

## Ranked Ownership And Source Placement

1. [UID:000038] `ControlPane` class: accepted direct owner/emitter. Evidence is the constructor role, vtable stores, class state helper relationships, and broad derived-control caller set.
2. [UID:0000IG] `ControlPane` file: accepted source route through the class, projected under `NexusTK/ui/core/ControlPane.cpp`; not the direct by-memory owner because the class is narrower and gate-cleared.
3. [UID:0000AW] `ProgressBarControlPane`: rejected direct owner. It consumes the `+0xf8/+0xfa/+0xfc` triplet and is physically adjacent, but it calls this constructor as a base and then installs its own vtables.
4. Concrete controls such as Rectangle, SelectBox, ObjectImage, UserShape, UserFace, Browser, and StaticText: rejected direct owners. They are caller/derived-class evidence.
5. `Pane`/`RectBounds`: dependencies only. `Pane(1)` and `SetBounds` implement inherited construction and layout mechanics; they do not own this derived `ControlPane` constructor.

## Recommended Metadata

Change only [UID:0002PB] target metadata:

- `COMPLETION:85` -> `COMPLETION:89`
- `CONFIDENCE:90` -> `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:000038`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:000038`
- Keep `EMITTER_POSITION_OPTIONAL:` blank
- Keep `Nested:4`

Score rationale:

- Completion rises because current MCP evidence and support-doc parity resolve the prior blocker list: exact body, exact boundary/padding, direct callees, vtable-store xrefs, 52 constructor refs, bounds pointer type, packed field map, source placement, rejected alternatives, and first-draft formal C++.
- Confidence rises because the active MCP session directly confirms the function, helper behavior, and vtable xrefs, and current executed reports agree on `RectBounds` pointer style and inherited field names. It remains below final-audit confidence because exact original spellings for `m_reservedControlState`, `m_controlFlags`, and the inherited range/current triplet are descriptive rather than symbol-proven.

Recommended item summary:

`Live MCP reanalysis resolves ControlPane::ControlPane source shape: exact 0xa1-byte constructor, Pane(1) base call, unsigned controlType byte, optional const RectBounds * SetBounds route, three ControlPane vtable stores, inherited range/current triplet zeroing, control flags/reserved byte defaults, visible/active/visual-state/hit-test defaults, 52 derived-control construction refs, and first-draft formal C++ readiness.`

## Recommended Target Doc Changes

For `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`:

- Update header metadata to `COMPLETION:89` and `CONFIDENCE:92`; leave owner/emitter/reconstructable metadata unchanged.
- Replace the blank formal C++ block with the exact range-safe constructor-only block above: use `Pane(1)` and `m_visualState(10)` literals, do not emit enum/type/constant declarations, and use neutral inherited range aliases unless implementation-time support inspection proves stronger accepted names.
- Update `Status` to state that first-draft C++ is now ready and emitted through [UID:000038]/[UID:0000IG], while original field names remain below final-audit.
- Refresh `Boundary Evidence` with current MCP `80de0a67` facts: `sub_4949E0` size `0xa1`, `0x00494a81-0x00494a90` all `0xcc`, `0x00494a90` not a function and begins the progress-bar raw setter.
- Expand `Behavior` / `IDA Evidence` with the current decompile/disasm facts, direct callee pair, vtable-store xrefs, 52 constructor xrefs, and corrected per-field interpretation for `+0xf8/+0xfa/+0xfc/+0xfe/+0xff/+0x100/+0x101/+0x102/+0x103/+0x104`.
- Add a `Source Shape` or equivalent section explaining why `unsigned char controlType, const RectBounds *bounds` is the source-facing signature, why `SetBounds(bounds, 0)` is the optional bounds route, and why vptr stores/EH scaffolding are compiler output.
- Replace stale `Open Questions` with evidence-backed remaining uncertainty: exact original names for `m_reservedControlState`, the control flags byte, and the inherited range/current triplet remain descriptive; `m_rangeStart`/`m_rangeCurrent`/`m_rangeEnd` are first-draft base aliases and ProgressBar may retain min/current/max aliases where proven.
- Add rejected alternatives: blank C++, target-local anonymous enum declarations, references to unowned constants, progress-specific triplet names in base formal code, raw `int *bounds`, exposing the `SetBounds` flags as constructor argument, one-dword packed state, progress/concrete-control ownership, direct file ownership, and handwritten vptr stores.
- Add a change-log entry for this B007 report and implementation callback recommendation.

## Recommended Support Doc Changes

For `by-class/ControlPane.md`:

- Add source-quality detail to the constructor method row: `ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)` builds `Pane(1)`, stores `m_controlType` at `+0xfe`, optionally applies bounds through `Pane::SetBounds(bounds, 0)`, initializes inherited range/current fields `+0xf8/+0xfa/+0xfc` as neutral base state, clears control flags/reserved state `+0xff/+0x100`, sets `m_controlVisible=true`, clears `m_controlActive`, sets `m_visualState=10`, and clears `m_ignoreHitTesting`.
- Add a support-only naming note: `kControlPaneMode = 1` and `kControlPaneVisualStateNormal = 10` are reasonable future class/file-level constant candidates, but [UID:0002PB] must not define them inside the by-memory formal block. If the class page does not already own those constants at implementation time, keep the target formal code literal-only.
- Add an evidence note with current MCP session `80de0a67`, function size `0xa1`, direct callees `0x00544460`/`0x00544bd0`, vtable refs `0x00617a90/0x00617af8/0x00617b28`, and 52 constructor xrefs.
- Keep class metadata unchanged at `86/88`: broader class-level blockers remain raw active-frame reachability, destructor representation, fixed virtual name, and final member spellings.

For `by-file/ControlPane.md`:

- Add the same constructor source-shape summary to the file role/proposed contents/evidence notes so the file route carries first-draft constructor readiness without forcing a class score bump.
- Keep file metadata unchanged at `86/88` for the same broader class/file blockers.

No edit needed for `by-class/Pane.md`, `by-memory/0x00544460-0x00545086.PaneCore.md`, `by-type/by-struct/PaneLayout.md`, `by-type/by-struct/RectBoundsLayout.md`, or `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` unless the supervisor wants a cross-reference note. Current inspection shows they already have equal-or-greater detail for `Pane::Pane(1)`, `Pane::SetBounds`, local bounds `+0x44`, origin `+0xac`, and `RectBounds` layout.

No edit needed for ProgressBar, Rectangle, SelectBox, UserShape, or UserFace support pages in this callback. They already contain equal-or-greater detail for their own constructor calls to `ControlPane`, the `RectBounds *bounds` style, `m_visualState` value `10`, `m_controlFlags` at `+0xff`, and the range/current triplet as inherited/progress-facing state. Current no-edit proof is conditional: if implementation-time inspection shows one of those pages is the only owner of a local enum constant, treat it as local evidence only and do not reference that constant from [UID:0002PB] unless `by-class/ControlPane.md` or `by-file/ControlPane.md` owns the declaration.

## Generated And Coverage Expectations

B007 must not edit generated files or coverage reports. After supervisor acceptance and implementation, expected supervisor/validator-owned follow-up:

- Run scoped validators for the changed target/support by-* docs.
- Run the normal executed-report lifecycle if the supervisor accepts the implemented report.
- Refresh generated/tracker state through validator-owned commands, not manual edits by B007.
- If the manual `by-memory/-coverage-report.md` row is updated by the supervisor, replace the stale [UID:0002PB] row with text equivalent to:

`[UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) 0x004949e0-0x00494a81 | constructor | ControlPane::ControlPane : reconstructable : 89% : very strong : B007 live MCP reanalysis resolves the source constructor shape: Pane(1) base construction, unsigned controlType byte, optional const RectBounds * bounds route through Pane::SetBounds(bounds,0), ControlPane vtable triplet stores, inherited range/current/control-state defaults, visible/active/visual-state/hit-test fields, 52 derived-control construction xrefs, class owner/emitter route, and first-draft formal C++ readiness.`

## Validator Results

Report-only pass: no validators were run before supervisor acceptance.

Implementation callback validators run from `source-3/project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory\0x004949e0-0x00494a81.ControlPaneConstructor.md --apply --queue-timeout 240`
  - `command_id: 000000003246`
  - `command_timestamp: 2026-06-26T19:50:03-04:00`
  - exit code `0`, `ok: 1`
  - generated refresh: `deferred`, `generated_refresh_command_id: 000000003246`, `generated_refresh_timestamp: 2026-06-26T19:50:03-04:00`
  - relevant diagnostics/side effects: metadata and registry updates for [UID:0002PB], formal block changed from blank to block, validator inserted missing UID links for [UID:0000IG] and [UID:000038], existing `missing_ref_target 000114` for stale `by-memory/0x004949e0-0x00494bf7.ControlPane.md`, validator-owned `projected_stats_update`.
- `python .\tools\validator.py --mode file --file by-class\ControlPane.md --apply --queue-timeout 240`
  - `command_id: 000000003247`
  - `command_timestamp: 2026-06-26T19:50:18-04:00`
  - exit code `0`, `ok: 1`
  - generated refresh: `deferred`, `generated_refresh_command_id: 000000003247`, `generated_refresh_timestamp: 2026-06-26T19:50:18-04:00`
  - relevant diagnostics/side effects: score/owner registry unchanged at `86/88` and [UID:0000IG], validator inserted missing UID link for [UID:0002PB], existing missing registry entries for split child UIDs `0003J8/0003J9/0003N2/0003N3/0003N4/0003N5/0003N6/0003N7/0003N9`, existing `missing_ref_target 000114`, validator-owned `projected_stats_update`.
- `python .\tools\validator.py --mode file --file by-file\ControlPane.md --apply --queue-timeout 240`
  - `command_id: 000000003249`
  - `command_timestamp: 2026-06-26T19:50:33-04:00`
  - exit code `0`, `ok: 1`
  - generated refresh: `deferred`, `generated_refresh_command_id: 000000003249`, `generated_refresh_timestamp: 2026-06-26T19:50:33-04:00`
  - relevant diagnostics/side effects: score/owner registry unchanged at `86/88` and `FILE`, validator inserted missing UID links for [UID:0002PB], existing missing registry entries for split child UIDs `0003J8/0003J9/0003N1/0003N2/0003N3/0003N4/0003N5/0003N6/0003N7/0003N9`, existing `missing_ref_target 000114`, validator-owned `projected_stats_update`.

No optional support by-* file was edited, so no optional support validators were required.

## Changed Files

- Modified: `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`.
- Modified: `by-class/ControlPane.md`.
- Modified: `by-file/ControlPane.md`.
- Modified: `tools/leaser/Agents/Agent-B007/research/0002PB-ControlPaneConstructor-source-quality.md` for checklist/proof updates.
- Not manually edited: generated files, project-level files, validator/tool state, IDA DB files, `by-memory/-coverage-report.md`, and all other `-coverage-report.md` files.
- Validator-owned side effects reported above: `projected_stats_update`, registry/reference updates, and deferred generated refresh metadata from scoped validator commands.
- Leases: B007 leased the three by-* edit files immediately before the edit/validator batch and released them immediately after validators. Release command succeeded for all three files. Current lease report after release shows no active B007 leases, only unrelated expired Supervisor leases from 2026-06-18.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `89/92`.
- Remaining uncertainty: exact original names for the zeroed `+0x100` byte, `+0xff` control flags, and range/current fields remain descriptive. The formal block now uses neutral source-facing base aliases for the range/current triplet, with ProgressBar-facing aliases reserved for support pages that prove those derived semantics; none of these names are PDB-proven original spellings.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the revised report and issued callback `B007-implement-0002PB-control-pane-constructor-source-quality-20260626`.
- [x] Target doc to update: `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`. Proof: metadata, formal C++, summary, MCP evidence, source-shape, field map, rejected alternatives, score rationale, and change log updated.
- [x] Support doc to update: `by-class/ControlPane.md`. Proof: constructor method row, class purpose/autogen wording, B007 evidence notes, support-only constant caveat, score rationale, and change log updated; score remains `86/88`.
- [x] Support doc to update: `by-file/ControlPane.md`. Proof: file role, proposed contents row, B007 evidence notes, support-only constant caveat, existing final-C++ caveat, and change log updated; score remains `86/88`.
- [x] No-edit proof to record during implementation for `by-class/Pane.md`, `by-memory/0x00544460-0x00545086.PaneCore.md`, `by-type/by-struct/RectBoundsLayout.md`, and `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` if they are not edited: proof recorded from inspection. `by-class/Pane.md` already documents `+0x44` local/bounds and bounds/layer membership; `PaneCore` already lists `Pane::Pane(unsigned char mode)` / `Pane::SetBounds`; `PaneLayout` already records `+0x44` local bounds, `+0xac` origin, and `+0xb5` mode; `RectBoundsLayout` already proves `sizeof(RectBounds)==16` and `left/top/right/bottom`; `RectGeometryHelpers` already documents `InitRectBounds`, `PointInRect`, and the same four-int layout.
- [x] No-edit proof to record during implementation for ProgressBar/Rectangle/SelectBox/UserShape/UserFace support pages if they are not edited: proof recorded from inspection. `by-class/ProgressBarControlPane.md` and `by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md` already prove `ControlPane(22, bounds)` and progress aliases `m_minValue/m_currentValue/m_maxValue`; `by-class/RectangleControlPane.md` and `by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md` already prove `ControlPane(8, bounds)` and `const RectBounds *bounds`; `by-class/SelectBoxControlPane.md` and `by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md` already prove `ControlPane` base construction, inherited `m_visualState` value `10`, and page-local constants only; `by-class/UserShapeSelectControlPane.md` and `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md` already prove `ControlPane(..., bounds)`, `m_controlFlags +0xff`, and inherited visual-state usage; `by-class/UserFaceSelectControlPane.md` and `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md` already prove the face selector constructor signature, `ControlPane` base call, `const RectBounds *bounds`, and `+0xff` as inherited control flag. No page-local constants were referenced from [UID:0002PB].
- [x] Target metadata to apply: `COMPLETION:89`, `CONFIDENCE:92`; keep `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank optional emitter, and `Nested:4`. Proof: target header now has `89/92`; owner/emitter/reconstructable/blank optional emitter/`Nested:4` preserved.
- [x] Insert exact range-safe formal `RECONSTRUCTION_CPP CODE` block from this report into the target: constructor code only, `Pane(1)`, `m_visualState(10)`, no anonymous enum/type/constant declarations, and no references to constants unless implementation-time support inspection proves accepted shared ownership. Proof: target formal block emits the exact constructor block from the revised report and text audit found no enum/constant declarations in the formal block.
- [x] Incorporate current MCP facts into the target: session `80de0a67`, health ok, modeled size `0xa1`, current schema/database requirement, direct callee pair, vtable-store refs, 52 constructor xrefs, and padding/sibling boundary. Proof: target `Boundary Evidence`, `IDA Evidence`, `Source Shape`, `Score Rationale`, and change log now record these facts; class/file support pages record the condensed session facts.
- [x] Incorporate bounds argument decision: source-facing `const RectBounds *bounds`; optional inherited `SetBounds(bounds, 0)` route; no exposed constructor flags argument. Proof: target formal C++ and `Source Shape` section use `const RectBounds *bounds` and document the rejected flags parameter; class/file support pages repeat the route.
- [x] Incorporate packed field map: inherited range/current triplet `+0xf8/+0xfa/+0xfc` as neutral base aliases `m_rangeStart`/`m_rangeCurrent`/`m_rangeEnd`, `m_controlType +0xfe`, `m_controlFlags +0xff`, reserved byte `+0x100`, visible byte `+0x101`, active byte `+0x102`, visual-state byte `+0x103 = 10`, and hit-test suppression byte `+0x104 = 0`. Proof: target `Packed Field Map` and formal C++ contain the neutral aliases and byte-wise defaults; class/file support pages summarize the same map.
- [x] Preserve rejected alternatives: blank C++, target-local anonymous enum declarations, references to unowned constants, progress-specific triplet names in base formal code, raw `int *bounds`, exposed SetBounds flag parameter, one-dword packed-state model, progress/concrete-control ownership, direct file ownership, and handwritten vptr stores. Proof: target `Rejected Alternatives` and change log contain the full list; support pages include the constant and alias caveats.
- [x] Preserve score rationale and remaining naming caveats as first-draft source-quality caps, not blockers. Proof: target score rationale now explains `89/92` and caps for original spellings; class/file score rationale remains unchanged except stale bounds blocker removed.
- [x] Run scoped validator for target by-memory file after implementation. Proof: command `000000003246`, timestamp `2026-06-26T19:50:03-04:00`, exit `0`, `ok:1`.
- [x] Run scoped validator for `by-class/ControlPane.md` if edited. Proof: command `000000003247`, timestamp `2026-06-26T19:50:18-04:00`, exit `0`, `ok:1`.
- [x] Run scoped validator for `by-file/ControlPane.md` if edited. Proof: command `000000003249`, timestamp `2026-06-26T19:50:33-04:00`, exit `0`, `ok:1`.
- [x] Do not edit generated files, project-level files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`; supervisor/validator owns generated/tracker/coverage refresh. Proof: no manual edits were made to those files; validator-owned `projected_stats_update`, registry/reference updates, and deferred generated refresh side effects are reported under `Validator Results`.
- [x] Supervisor-owned coverage/tracker refresh expected after implementation/execution; use the suggested coverage-row wording above if a manual coverage row is maintained. Proof: no manual coverage report edited; source target item summary was updated for validator-owned generated coverage, and the suggested manual row remains report text only.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback received in `goal.md` and current user instruction.
- [x] Leases acquired only for immediate target/support by-* edits. Proof: B007 leased only `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`, `by-class/ControlPane.md`, and `by-file/ControlPane.md` immediately before patching and validation.
- [x] All accepted target/support details incorporated at report-level detail or explicitly recorded as already present at same-or-greater detail. Proof: target/class/file docs updated; optional Pane/RectBounds/derived support pages recorded as no-edit proof above.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: target `85/90` -> `89/92`, owner/emitter/reconstructable unchanged, exact formal C++ inserted; class/file scores unchanged by accepted support-doc disposition.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target rejected alternatives and support notes include stale enum/constant, progress-alias, repeat-delay, one-dword-state, ownership, direct-file, raw-bounds, and handwritten-vptr rejections.
- [x] Open questions resolved or documented as evidence-backed unresolved naming caveats. Proof: target `Open Questions` now resolves bounds/type and visual-state blocker, leaving only exact original spelling caveats for reserved/control/range fields; support pages remove stale bounds-argument blocker.
- [x] Scoped validators run and results recorded with command ids/timestamps if validator returns them. Proof: commands `000000003246`, `000000003247`, and `000000003249` recorded above with timestamps, exit code `0`, `ok:1`, and generated-refresh state.
- [x] Leases released immediately after edit/validator batch. Proof: `python .\tools\leaser\leaser.py B007 unlease ...` returned `Success` for all three files; current lease report shows no active B007 leases.
- [x] Remaining unapplied accepted items listed with exact blocker, or none. Proof: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002PB-ControlPaneConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002PB-ControlPaneConstructor-source-quality.md","timestamp":"2026-06-26T19:58:38","uid":"0002PB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
