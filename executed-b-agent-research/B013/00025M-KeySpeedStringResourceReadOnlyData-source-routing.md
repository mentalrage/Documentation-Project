** TARGET-REPORT-UID:00025M **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00025M KeySpeedStringResourceReadOnlyData Source-Routing Report

Status: FINISHED

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00025M] `0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData` as a non-reconstructable mixed `.rdata` index, but repair the child model before raising the page.
- Final disposition for [UID:00025M]: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Required action after supervisor acceptance: split/repair the exact children under this island. The current exact [UID:00031P] `KeySpeedMgrVtableData` child is overbroad if it claims exact KeySpeedMgr RTTI/vtable ownership because it includes two non-slot `0x400` constants at `0x0061c9d4` and `0x0061c9d8`; those constants are much better explained as LanguageMan parser limit constants.
- Recommended target score after implementation: `COMPLETION:86`, `CONFIDENCE:92`. Until the child repair is applied, the current `83/91` cap is defensible because LanguageMan vtable/string children are missing and the `0x400` constants are misrouted.
- Confidence: high for the aggregate no-code decision and the exact byte boundaries; medium-high for assigning the two `0x400` constants to LanguageMan parser limits because that is contextual rather than address-xref-proven.

No by-* docs, generated files, or coverage reports were edited.

## Target

- Target UID: `00025M`
- Target path: `source-3/project-documentation/by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/00025M-KeySpeedStringResourceReadOnlyData-source-routing.md`
- Current target metadata: `COMPLETION:83`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Current child: [UID:00031P] `source-3/project-documentation/by-memory/0x0061c9c4-0x0061c9dc.KeySpeedMgrVtableData.md`
- Current coverage row: [UID:00025M] is ignored/non-reconstructable; [UID:00031P] is the only nested row.

## Evidence Checked

- Assignment rules: `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `source-3/project-documentation/tools/leaser/Agents/Agent-B013/goal.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Target/support docs: [UID:00025M], [UID:00031P], [UID:0001XX] `KeySpeedMgrVtable`, [UID:0000KJ] `KeySpeedMgr`, [UID:00006Z] `KeySpeedMgr`, [UID:0000KK] `LanguageMan`, [UID:000071] `LanguageMan`, [UID:000072] `LanguageManager`, [UID:00018R] `LanguageManLocalization`, [UID:00018S] `LanguageManCleanupDestructor`, [UID:00018T] `LocalizationAdjacentZeroInitializer`, [UID:00018U] `LanguageManLookupAndSingletonHelpers`, [UID:00018V] `LanguageManScalarDeletingDestructor`, [UID:0001RP] `str-res-localized-strings`, and successor [UID:00025N] `LayerInputListReadOnlyData`.
- Generated/read-only evidence: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `project-level/-unresolved.md`, and `project-level/-resolved.md`.
- Prior B-report evidence: B013's `00018U-LanguageManLookupAndSingletonHelpers-source-quality.md`; executed B001 `00018T` reports were used only as supporting context for the LanguageMan read-only-data source-order inference.
- Local validator baseline: `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md --uid-only`; result: `ok: 1`.
- IDA MCP probe at `http://127.0.0.1:13337/mcp`: unavailable (`Unable to connect to the remote server`).
- Local read-only PE scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`.
- Capstone disassembly was used locally only to confirm the `0x400` immediate uses in the LanguageMan constructor and their absence from the KeySpeedMgr code island.
- `int_convert.py` was used for decimal conversions: `0x80` = 128, `0x18` = 24, `0x10` = 16, `0x24` = 36, `0x400` = 1024, `0x27c` = 636, `0x32` = 50, and `0xa7` = 167.

## Exact Byte Inventory

The target range is exactly `0x80` / 128 bytes (Verified with `int_convert.py`).

| Range / address | Bytes / value | Best source-facing role | Owner recommendation |
| --- | --- | --- | --- |
| `0x0061c9c4` | dword `0x00649820` | `KeySpeedMgr` complete-object locator pointer, `??_R4KeySpeedMgr@@6B@`. | [UID:00006Z] `KeySpeedMgr` class via exact vtable child. |
| `0x0061c9c8` | dword `0x004effc0` | `KeySpeedMgr` scalar deleting destructor slot. | [UID:00006Z]. |
| `0x0061c9cc` | dword `0x004f4b10` | inherited `LObject` identity/class-name slot. | [UID:00006Z] vtable slot inherited from `LObject`. |
| `0x0061c9d0` | dword `0x0041b6c0` | inherited/default no-op virtual slot. | [UID:00006Z] vtable slot inherited/default. |
| `0x0061c9d4` | dword `0x00000400` | non-slot constant, decimal `1024` (Verified with `int_convert.py`), likely `LanguageMan` max line bytes. | Best route [UID:0000KK] `LanguageMan.cpp`; not KeySpeedMgr. |
| `0x0061c9d8` | dword `0x00000400` | non-slot constant, decimal `1024` (Verified with `int_convert.py`), likely `LanguageMan` max string count. | Best route [UID:0000KK] `LanguageMan.cpp`; not KeySpeedMgr. |
| `0x0061c9dc` | dword `0x006498c0` | `LanguageMan` complete-object locator pointer, `??_R4LanguageMan@@6B@`. | [UID:000071] `LanguageMan` class via new vtable child. |
| `0x0061c9e0` | dword `0x004f03d0` | `LanguageMan` scalar deleting destructor slot. | [UID:000071]. |
| `0x0061c9e4` | dword `0x004f4b10` | inherited `LObject` identity/class-name slot. | [UID:000071] vtable slot inherited from `LObject`. |
| `0x0061c9e8` | dword `0x0041b6c0` | inherited/default no-op virtual slot. | [UID:000071] vtable slot inherited/default. |
| `0x0061c9ec-0x0061c9fc` | UTF-16 `str.res`, `0x10` / 16 bytes including terminator (Verified with `int_convert.py`). | DAT resource filename literal used by the LanguageMan loader. | [UID:0000KK] `LanguageMan.cpp`, with [UID:0001RP] as resource contract support. |
| `0x0061c9fc-0x0061ca1e` | UTF-16 `Too many strings`, 34 bytes including terminator. | LanguageMan parser diagnostic/throw text for the 1024-record cap. | [UID:0000KK]. |
| `0x0061ca1e-0x0061ca20` | two zero bytes | alignment between UTF-16 literals. | compiler/linker alignment inside LanguageMan string literal island. |
| `0x0061ca20-0x0061ca44` | UTF-16 `Invalid String ID`, `0x24` / 36 bytes including terminator (Verified with `int_convert.py`). | LanguageMan invalid-id fallback literal. | [UID:0000KK], with [UID:00018U] and [UID:0001RP] support. |

The successor at `0x0061ca44` is the `Layer` complete-object locator pointer, `0x00649960`, and belongs to [UID:00025N]. The predecessor [UID:00025L] ends exactly at `0x0061c9c4`.

## PE/Xref Facts

Local PE absolute dword-ref scan:

- `0x0061c9c8` has three `.text` references at `0x004efecd`, `0x004efee2`, and `0x004effc8`, matching KeySpeedMgr constructor/destructor/scalar-deleting-destructor vptr stores.
- `0x0061c9e0` has three `.text` references at `0x004f007d`, `0x004f02b9`, and `0x004f0400`, matching LanguageMan constructor, non-deleting cleanup destructor, and scalar deleting destructor vptr stores.
- `0x0061c9ec` has one `.text` reference at `0x004f009a`, the `str.res` loader literal.
- `0x0061c9fc` has one `.text` reference at `0x004f0262`, the `Too many strings` parser diagnostic.
- `0x0061ca20` has two `.text` references at `0x004f036a` and `0x004f03aa`, the direct-return and copy-out invalid-id fallback paths.
- `0x004f03d0` has one `.rdata` reference at `0x0061c9e0`; `0x004effc0` has one `.rdata` reference at `0x0061c9c8`.
- No address refs were found to `0x0061c9c4`, `0x0061c9dc`, `0x0061c9d4`, or `0x0061c9d8`. This is expected for RTTI locator pointers and concerning only for the two `0x400` constants.

Local constructor disassembly around the `0x400` immediates:

- `0x004f011f`: `cmp esi, 0x400`, capping an input line at 1024 bytes.
- `0x004f0167`: `push 0x400`, passing a 1024-wide-character conversion-buffer capacity.
- `0x004f01d1`: `cmp eax, 0x400`, enforcing the 1024-record/string-count cap before the `Too many strings` diagnostic path.
- The same raw pattern was not found in the `0x004efea0-0x004f0008` KeySpeedMgr code island. This rejects KeySpeedMgr behavioral ownership for the two `0x400` dwords even though older docs placed them in the KeySpeedMgr child.

## Heuristic / Inference Reanalysis And Validation

### KeySpeedMgr Vtable Boundary

Existing docs correctly identify the KeySpeedMgr RTTI/vtable head, but [UID:00031P] is overbroad if it is intended to be the exact KeySpeedMgr vtable-data child. The true KeySpeedMgr RTTI/vtable bytes are `0x0061c9c4-0x0061c9d4`: one complete-object locator pointer and three virtual slots. The two following dwords at `0x0061c9d4` and `0x0061c9d8` are not function pointers, have no address xrefs, have no KeySpeedMgr code correlation, and equal the LanguageMan parser limits.

Best recommendation: rename/narrow [UID:00031P] to `0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData.md`, remove the two `0x400` constants from its vtable layout, and keep its owner/emitter route [UID:00006Z] `KeySpeedMgr`.

Rejected alternative: keep `0x0061c9c4-0x0061c9dc` as exact KeySpeedMgr-owned data. This is weaker because KeySpeedMgr behavior is keyboard delay/speed only, the KeySpeedMgr code island contains no `0x400` immediate pattern, and the constants match LanguageMan parser caps.

### LanguageMan Parser Limit Constants

Best source-facing role: two LanguageMan parser constants, probably `kMaxStringResourceLineBytes = 1024` and `kMaxLocalizedStringCount = 1024`.

Evidence:

- Both constants are `0x400` / decimal `1024` (Verified with `int_convert.py`).
- The LanguageMan constructor uses `0x400` for the per-line byte cap, conversion-buffer capacity, and string-record cap.
- `str-res-localized-strings.md` independently documents a 1024-record maximum and 1024-byte input-line limit.
- No KeySpeedMgr code or source behavior uses a 1024 limit.
- The constants are physically adjacent to the LanguageMan RTTI/vtable/string island.

Remaining caveat: no address xrefs target `0x0061c9d4` or `0x0061c9d8`, so this is a source-order/value inference, not address-reference proof. They may be file-scope constants emitted by the compiler even though the executable code uses immediates, or retained/pooled constants from the same object file. That caveat should cap confidence below final-audit quality but should not leave them under KeySpeedMgr.

### LanguageMan Vtable Child Need

The target lacks an exact child for `0x0061c9dc-0x0061c9ec`. This is a straightforward missing child:

- `0x0061c9dc -> 0x006498c0`, LanguageMan complete-object locator pointer.
- `0x0061c9e0 -> 0x004f03d0`, scalar deleting destructor slot.
- `0x0061c9e4 -> 0x004f4b10`, inherited `LObject` identity/class-name slot.
- `0x0061c9e8 -> 0x0041b6c0`, inherited/default no-op slot.
- Vptr stores to `0x0061c9e0` occur in LanguageMan constructor/destructor/deleting-destructor paths.
- The following byte at `0x0061c9ec` begins `L"str.res"`, so the vtable child end is exact.

Recommended new child: `by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000071`, `EMITTER_UIDS:000071`, scores around `86/91`. Formal C++ should be blank or a comment-only marker because the vtable is compiler-generated from the class declaration.

### LanguageMan String-Literal Island

The string-literal island `0x0061c9ec-0x0061ca44` has one direct source owner: [UID:0000KK] `LanguageMan.cpp`. [UID:0001RP] owns the DAT payload/format contract, not these C++ string literals as a memory item.

Best source-facing roles:

- `kStringResourceName = L"str.res"`: filename literal passed to the DAT-backed loader.
- `kTooManyStringsMessage = L"Too many strings"`: parser diagnostic/exception message when the 1024-string cap is exceeded.
- `kInvalidStringIdText = L"Invalid String ID"`: fallback returned/copied by lookup helpers.

Recommended new child: `by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000KK`, `EMITTER_UIDS:0000KK`, scores around `87/93`. It should document the internal string extents and the two-byte alignment at `0x0061ca1e-0x0061ca20`. First-draft source shape is ready:

```cpp
namespace {
const wchar_t kStringResourceName[] = L"str.res";
const wchar_t kTooManyStringsMessage[] = L"Too many strings";
const wchar_t kInvalidStringIdText[] = L"Invalid String ID";
}
```

Final names are descriptive, not original-proof. If the implementation prefers exact-per-literal children, split this child into `0x0061c9ec-0x0061c9fc`, `0x0061c9fc-0x0061ca20`, and `0x0061ca20-0x0061ca44`; however, one LanguageMan string-literal child is sufficient and cleaner because all three literals share one file owner and one parser/lookup contract.

### Aggregate Ownership And No-Code Proof

[UID:00025M] must remain non-reconstructable as one unit:

- It crosses at least two direct class owners: [UID:00006Z] `KeySpeedMgr` and [UID:000071] `LanguageMan`.
- It also contains LanguageMan file-level constants/string literals, not just class vtables.
- The successor [UID:00025N] begins at the `Layer` locator and proves the end boundary.
- No original C++ source item would declare "KeySpeedMgr vtable plus LanguageMan parser constants/vtable/strings" as one hand-authored object.
- Exact children can carry all rebuild-relevant declarations; aggregate C++ would duplicate or pollute those children.

The current target no-code proof remains valid, but it needs to be updated to include LanguageMan vtable and parser-limit constants, not only KeySpeedMgr vtable and LanguageMan strings.

## Ranked Ownership Analysis

### 1. Mixed non-emitting index [UID:00025M]

- Evidence for: physical range spans several rebuild-relevant source data items from different direct owners; successor/predecessor boundaries are strong; exact children can cover each item.
- Evidence against: none for aggregate/index disposition. The only issue is that current child coverage is incomplete.
- Decision: keep target `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/C++.

### 2. [UID:00006Z] KeySpeedMgr for `0x0061c9c4-0x0061c9d4`

- Evidence for: RTTI/vtable labels, vptr stores from KeySpeedMgr constructor/destructor/deleting destructor, matching class/file pages.
- Evidence against: does not own the two following `0x400` constants.
- Decision: accept only for the narrowed exact vtable child.

### 3. [UID:0000KK] LanguageMan for `0x0061c9d4-0x0061ca44`

- Evidence for: constructor `0x400` uses, LanguageMan vptr stores, `str.res` loader xref, diagnostics/fallback xrefs, resource contract, existing source file route `NexusTK/localization/`.
- Evidence against: the two `0x400` rdata constants lack direct address xrefs, so their storage/names are inferred.
- Decision: accept for string-literal child; accept as best direction for parser-limit child with confidence cap.

### 4. [UID:000071] LanguageMan class for `0x0061c9dc-0x0061c9ec`

- Evidence for: RTTI/vtable bytes and vptr stores; [UID:00018S]/[UID:00018V] write the same vtable; class parent clears `86/88`.
- Evidence against: none.
- Decision: create exact vtable-data child with class owner/emitter.

### Rejected Alternatives

- [UID:0001RP] `str-res-localized-strings` as canonical owner for the string-literal memory: rejected because it owns the external DAT payload/format contract, while the three `.rdata` literals are LanguageMan C++ source literals.
- [UID:0000KJ] `KeySpeedMgr` owning `0x0061c9d4-0x0061c9d8`: rejected because the constants match LanguageMan limits and no KeySpeedMgr code uses the value.
- [UID:000072] `LanguageManager`: rejected as generated alias; docs and RTTI evidence point to `LanguageMan` / `Singleton<LanguageMan>`, not a second object.
- [UID:0001Z7] `ReadOnlyDataSection`: useful enclosing map only; not a source owner.
- Successor [UID:00025N] `LayerInputListReadOnlyData`: rejected because the hard boundary starts at `0x0061ca44`.

## Recommended Future Implementation Checklist

1. Update [UID:00025M] target inventory to list all subitems:
   - `0x0061c9c4-0x0061c9d4`: KeySpeedMgr complete-object locator plus three-slot vtable.
   - `0x0061c9d4-0x0061c9dc`: two LanguageMan parser-limit constants, both `0x400` / 1024 (Verified with `int_convert.py`), no direct address xrefs, best source route LanguageMan.
   - `0x0061c9dc-0x0061c9ec`: LanguageMan complete-object locator plus three-slot vtable.
   - `0x0061c9ec-0x0061ca44`: LanguageMan string-resource filename, parser diagnostic, invalid-id fallback, and two-byte alignment.
2. Rename/narrow [UID:00031P] from `0x0061c9c4-0x0061c9dc.KeySpeedMgrVtableData.md` to `0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData.md`. Keep its UID. Remove the two `0x400` constants from the KeySpeedMgr layout and score it about `88/92`.
3. Create `by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md`. Recommended metadata: `COMPLETION:86`, `CONFIDENCE:87`, `CANONICAL_OWNER:0000KK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KK`. Include the no-address-xref caveat and the constructor immediate-use evidence. First-draft C++ if accepted:

```cpp
namespace {
const int kMaxStringResourceLineBytes = 1024;
const int kMaxLocalizedStringCount = 1024;
}
```

4. Create `by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md`. Recommended metadata: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:000071`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000071`. Formal C++ should stay blank or comment-only as compiler-generated vtable data.
5. Create `by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md`. Recommended metadata: `COMPLETION:87`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000KK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KK`. Include first-draft literal declarations from the previous section.
6. Create or update a support type page `by-type/by-vtable/LanguageManVtable.md` if the implementation wants parity with [UID:0001XX] `KeySpeedMgrVtable`. Recommended owner [UID:000071], route through [UID:0000KK].
7. Update [UID:0001XX] `KeySpeedMgrVtable` to state that the exact KeySpeedMgr vtable ends at `0x0061c9d4`; the following `0x400` constants are not KeySpeedMgr data and are better modeled as LanguageMan parser limits.
8. Update [UID:0000KK] `LanguageMan`, [UID:000071] `LanguageMan`, [UID:00018R], [UID:00018U], [UID:00018V], and [UID:0001RP] to link the new LanguageMan vtable/string/constant children where relevant.
9. Update [UID:00025M] target score to `86/92`, keeping owner/emitter/C++ blank and `RECONSTRUCTABLE:FALSE`.
10. Do not edit `by-memory/-coverage-report.md` directly from B013; use the row text below.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` directly from this report. After the supervisor accepts the implementation direction and new child UIDs are assigned, replace the current [UID:00025M] block at lines near the existing row with this text. `UID_NEW_*` placeholders must be replaced with validator-assigned UIDs when the new files are created; all other row text is exact.

```markdown
    - [UID:00025M][0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData](by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md) 0x0061c9c4-0x0061ca44 | vtable/string-data | KeySpeedStringResourceReadOnlyData : ignored : 86% : strong : B013 source-routing pass keeps this as a non-emitted mixed `.rdata` index, but repairs the child model: exact KeySpeedMgr RTTI/vtable data is `0x0061c9c4-0x0061c9d4`, the two `0x400` constants at `0x0061c9d4-0x0061c9dc` are best modeled as LanguageMan parser limit constants, `0x0061c9dc-0x0061c9ec` is the missing LanguageMan RTTI/vtable child, and `0x0061c9ec-0x0061ca44` is the LanguageMan `str.res`/diagnostic/fallback string-literal island. PE bytes and refs confirm KeySpeedMgr vtable stores at `0x004efecd`/`0x004efee2`/`0x004effc8`, LanguageMan vtable stores at `0x004f007d`/`0x004f02b9`/`0x004f0400`, string refs at `0x004f009a`/`0x004f0262`/`0x004f036a`/`0x004f03aa`, and hard successor `Layer` boundary at `0x0061ca44`; no aggregate owner/emitter/C++ should be set.
        - [UID:00031P][0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData](by-memory/0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData.md) 0x0061c9c4-0x0061c9d4 | vtable-data | KeySpeedMgrVtableData : reconstructable : 88% : strong : Exact KeySpeedMgr complete-object locator and three-slot primary vtable only; PE refs tie `0x0061c9c8` to KeySpeedMgr constructor/destructor/scalar-deleting-destructor stores, while the former tail `0x400` constants are excluded because they are not vtable slots and match LanguageMan parser limits.
        - [UID:UID_NEW_LIMITS][0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants](by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md) 0x0061c9d4-0x0061c9dc | const-data | LanguageMan parser limit constants : reconstructable : 86% : strong : Two `0x400` / 1024 dwords best routed to LanguageMan.cpp as string-resource line/count limits; no direct address xrefs were found, but LanguageMan constructor immediates use `0x400` for line-byte cap, conversion-buffer capacity, and loaded-string count cap, while KeySpeedMgr code has no `0x400` pattern.
        - [UID:UID_NEW_LMANVT][0x0061c9dc-0x0061c9ec.LanguageManVtableData](by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md) 0x0061c9dc-0x0061c9ec | vtable-data | LanguageManVtableData : reconstructable : 86% : strong : Exact LanguageMan complete-object locator plus scalar-deleting-destructor, inherited `LObject` identity, and inherited/default no-op slots; PE refs tie vtable base `0x0061c9e0` to constructor, cleanup destructor, and scalar deleting destructor stores, with `L"str.res"` beginning at the exact successor boundary.
        - [UID:UID_NEW_LMANSTR][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md) 0x0061c9ec-0x0061ca44 | string-literal-data | LanguageMan string resource literals : reconstructable : 87% : very strong : Exact LanguageMan UTF-16 literal island for `str.res`, `Too many strings`, and `Invalid String ID`; refs land in the LanguageMan loader, parser diagnostic, and lookup/copy fallback helpers, with a two-byte alignment gap before the final fallback literal and the `Layer` locator boundary immediately after.
```

If the supervisor chooses not to split the two `0x400` constants yet, do not raise the parent above `84/91`; the constants should at minimum be removed from KeySpeedMgr-specific prose and documented as a LanguageMan-directed uncertainty.

## Validation Commands Needed After Implementation

Run these after applying the accepted target/support edits and creating/moving child pages:

> Executable block R001 was removed from this report and preserved verbatim in [00025M-KeySpeedStringResourceReadOnlyData-source-routing-removed.md](00025M-KeySpeedStringResourceReadOnlyData-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:00031P] is renamed/moved, also run a documented missing-entry cleanup only if validator reports stale UID path state.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/00025M-KeySpeedStringResourceReadOnlyData-source-routing.md`
- Modified: none outside the B013 research folder.
- Moved/renamed: none.
- Coverage reports edited: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00025M-KeySpeedStringResourceReadOnlyData-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00025M"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00025M-KeySpeedStringResourceReadOnlyData-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00025M-KeySpeedStringResourceReadOnlyData-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00025M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
