** TARGET-REPORT-UID:00018O **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00018O KeySpeedMgr Aggregate Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:00018O] `KeySpeedMgr` from an emitting reconstructable method cluster to a reviewed non-emitting exact split/index page over the KeySpeedMgr code island.
- Final disposition: aggregate page should remain blank and should not emit C++. Exact child pages own the constructor/destructor/load/restore/raw setter/fast-repeat/scalar-wrapper decisions.
- Required action after supervisor review: update [UID:00018O] to `COMPLETION:90`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:00006Z`, change `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, and replace stale "blank below 95/95 source gate" text with the explicit container/no-source-body policy.
- Confidence: strong. Exact boundaries, padding, child inventory, singleton/vtable evidence, and caller routes are stable. Current-session IDA MCP was unavailable, so this report uses existing live-IDA docs plus raw PE/export checks from this pass and recent child B reports.

No target/support by-* docs or `by-memory/-coverage-report.md` were edited during this report-only pass.

## Target

- Target UID: `00018O`
- Target path: `source-3/project-documentation/by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00018O-KeySpeedMgr-source-quality.md`
- Current metadata: `84/90`, `CANONICAL_OWNER:00006Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006Z`, blank formal C++.
- Current generated output: `auto-generated/NexusTK/input/KeySpeedMgr.cpp` emits [UID:0002IQ] `KeySpeedMgr::~KeySpeedMgr()` and empty markers for [UID:00018O], constructor, load, restore, scalar wrapper, vtable/layout/global pages, raw setter, and fast-repeat helper.

## Evidence Checked

- Rule docs: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `tools/leaser/Agents/Agent-B010/goal.md`, `by-structure.md`.
- Target/support docs: [UID:00018O], [UID:00006Z] `KeySpeedMgr`, [UID:0000KJ] `KeySpeedMgr`, [UID:0001UV] `KeySpeedMgrLayout`, [UID:0001XX] `KeySpeedMgrVtable`, [UID:0000RB] `g_pKeySpeedMgr`, [UID:0001P7] memory global, [UID:00031P] vtable data, [UID:00032A] `DestroyKeySpeedMgr`.
- Exact child docs: [UID:0002IP], [UID:0002IQ], [UID:0002IR], [UID:00018P], [UID:0002IS], [UID:00018Q], [UID:0002IT].
- Recent child reports: B014 constructor, B003 ordinary destructor, B015 load, B007 restore, B012 scalar deleting destructor, A002 raw setter audit.
- Generated/project state: `auto-generated/-ag-memory-coverage.md`, `auto-generated/NexusTK/input/KeySpeedMgr.cpp`, `project-level/-auto-completion-stats.md`, `project-level/-unresolved.md`, `by-memory/-coverage-report.md`, `by-project-structure/proposed-source-tree.md`.
- IDA MCP status: direct probe to `http://127.0.0.1:13337/mcp` failed with `MCP_ERROR: Unable to connect to the remote server`.
- Independent raw PE scan in this pass used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- `int_convert.py` verified `0x0c` as 12, `0x1f` as 31, `0x31` as 49, `0x1d` as 29, `0x48` as 72, `0x2d` as 45, `0x25` as 37, and `0x168` as 360.

## Raw PE / Route Facts

The aggregate range is `0x004efea0-0x004f0008`, size `0x168` / 360 bytes (Verified with int_convert.py). Raw PE bytes and rel32/VA scans confirm:

| Range | Role | Size | Route evidence |
| --- | --- | ---: | --- |
| `0x004efea0-0x004efedd` | constructor | `0x3d` | one rel32 caller `0x00463a9a`; no VA pointer hits |
| `0x004efedd-0x004efee0` | padding | 3 bytes | `cc cc cc` |
| `0x004efee0-0x004efef5` | ordinary destructor | 21 bytes | no rel32 or VA pointer route; source destructor variant |
| `0x004efef5-0x004eff00` | padding | 11 bytes | all `0xcc` |
| `0x004eff00-0x004eff25` | load method | `0x25` / 37 bytes (Verified with int_convert.py) | one rel32 caller `0x00463aae`; no VA pointer hits |
| `0x004eff25-0x004eff30` | padding | 11 bytes | all `0xcc` |
| `0x004eff30-0x004eff5d` | restore method | `0x2d` / 45 bytes (Verified with int_convert.py) | rel32 callers `0x00464aff`, `0x00466adb`, `0x004ab844`, `0x004f5ee6` |
| `0x004eff5d-0x004eff60` | padding | 3 bytes | `cc cc cc` |
| `0x004eff60-0x004eff91` | raw two-argument setter | `0x31` / 49 bytes (Verified with int_convert.py) | no rel32 route and no VA pointer hits |
| `0x004eff91-0x004effa0` | padding | 15 bytes | all `0xcc` |
| `0x004effa0-0x004effbd` | fast-repeat helper | `0x1d` / 29 bytes (Verified with int_convert.py) | rel32 callers `0x00463ab5`, `0x00466a24`; no VA pointer hits |
| `0x004effbd-0x004effc0` | padding | 3 bytes | `cc cc cc` |
| `0x004effc0-0x004f0008` | scalar deleting destructor | `0x48` / 72 bytes (Verified with int_convert.py) | no rel32 route; one VA hit at vtable slot `0x0061c9c8` |
| `0x004f0008-0x004f0010` | successor padding | 8 bytes | all `0xcc`; next executable island is LanguageMan |

The raw setter bytes decode to a frame-based callee-pop function: read `[ebp+8]` delay and `[ebp+0c]` speed, apply delay only when `delay <= 3`, apply speed only when `speed <= 0x1f` / 31 (Verified with int_convert.py), call `SystemParametersInfoW` with actions `0x17`/`0x0b`, and return with `retn 8`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Direct parent | Current score | Recommendation |
| --- | --- | --- | --- | --- | --- |
| `0x004efea0-0x004f0008` | [UID:00018O] aggregate | exact KeySpeedMgr code-island split index | [UID:00006Z] containment | `84/90` | `90/92`, `RECONSTRUCTABLE:FALSE`, no emitter, blank C++ |
| `0x004efea0-0x004efedd` | [UID:0002IP] constructor | source-authored class constructor | [UID:00006Z] | `84/90` | accept B014 `88/92`, first-draft C++ |
| `0x004efee0-0x004efef5` | [UID:0002IQ] ordinary destructor | source-authored destructor body | [UID:00006Z] | `87/92` | already emits `g_pKeySpeedMgr = 0;` |
| `0x004eff00-0x004eff25` | [UID:0002IR] load | source-authored class method | [UID:00006Z] | `84/90` | accept B015 `87/92`, first-draft C++ |
| `0x004eff30-0x004eff5d` | [UID:00018P] restore | source-authored class method | [UID:00006Z] | `84/90` | accept B007 `88/92`, first-draft C++ |
| `0x004eff60-0x004eff91` | [UID:0002IS] raw setter | retained file-local helper | [UID:0000KJ] | `85/90` | `87/91`, first-draft `static void __stdcall ApplyKeyboardRepeatSettings(UINT, UINT)` |
| `0x004effa0-0x004effbd` | [UID:00018Q] fast repeat | file-local helper | [UID:0000KJ] | `86/91` | `88/92`, first-draft `static void ApplyFastKeyboardRepeatSettings()` |
| `0x004effc0-0x004f0008` | [UID:0002IT] scalar deleting destructor | source-declared/generated-binary MSVC wrapper | [UID:00006Z] | `84/90` | accept B012 `86/91`, no handwritten body; comment-only marker if policy requires emitted proof |

## Heuristic / Inference Reanalysis And Validation

### Aggregate Versus Child Ownership / Emission

Best inference: [UID:00018O] is an exact method-family index/container, not a source-level object to emit.

Evidence:
- The page spans multiple independent functions, file-local helpers, compiler wrapper output, and padding.
- Exact children already carry the real source ownership: class methods to [UID:00006Z], file-local helpers to [UID:0000KJ], scalar wrapper to class-specific generated-binary policy.
- `by-structure.md` says a reviewed container should be `RECONSTRUCTABLE:FALSE` when exact children carry the source ownership and the container itself is only an audit/index map.
- Current autogen emits an empty marker for [UID:00018O], which is misleading because the aggregate has no independent source body and should not become a synthetic `KeySpeedMgr` method.

Rejected alternatives:
- Keep [UID:00018O] as `RECONSTRUCTABLE:TRUE` and emit `[[CHILDREN]]`: unnecessary and unsafe for a by-memory range that mixes class methods, file-local helpers, generated wrapper code, and padding. The class/file pages are better source roots.
- Paste all child C++ into the aggregate: rejected because by-memory code must not include source for sibling/child ranges when exact children exist.
- Clear `CANONICAL_OWNER` entirely: rejected. The physical code island is still semantically a `KeySpeedMgr` class/file neighborhood; [UID:00006Z] remains the best containment owner.

### Source Placement

Keep [UID:0000KJ] `NexusTK/input/KeySpeedMgr.cpp`.

Evidence:
- `proposed-source-tree.md` places `KeySpeedMgr.cpp` under `NexusTK/input/`.
- The file page documents a focused input/platform manager: preserve Windows keyboard repeat settings, apply fast repeat during active gameplay, restore on cleanup/deactivation/error/exit.
- [UID:0000K6] `InputMan` handles input messages and IME state; `KeySpeedMgr` only manages Win32 `SystemParametersInfoW` keyboard repeat state.
- `Application` and `WinMain` are callers/cleanup orchestrators, not owners of the manager's object fields or helper family.

Rejected alternatives:
- `platform/KeySpeedMgr.cpp`: plausible broad category because this uses Win32 APIs, but current source tree, file page, startup sequence, and input-specific behavior favor `input/KeySpeedMgr.cpp`.
- `Application.cpp` or `WinMain.cpp`: rejected for methods/helpers; those are lifecycle consumers. [UID:00032A] `DestroyKeySpeedMgr` remains WinMain-owned cleanup glue.
- `InputMan.cpp`: rejected because no `InputMan` state, IME state, message dispatch, or input-target list is touched.

### Field / Global Names

Resolved names:
- `dword_67AB48` / `DAT_0067ab48` = `g_pKeySpeedMgr`, type `KeySpeedMgr *`.
- `this+0x04` / `mbr_0x4` = `m_savedKeyboardDelay`.
- `this+0x08` / `mbr_0x8` = `m_savedKeyboardSpeed`.

Evidence:
- Constructor initializes `+0x04` and `+0x08` to invalid sentinel `UINT(-1)`.
- Load passes `&m_savedKeyboardDelay` to `SPI_GETKEYBOARDDELAY` and `&m_savedKeyboardSpeed` to `SPI_GETKEYBOARDSPEED`.
- Restore and the two file-local setters use exactly the Windows valid ranges: delay `0..3`, speed `0..31` (31 Verified with int_convert.py).
- `g_pKeySpeedMgr` has constructor write, destructor/scalar-wrapper clears, restore/fast-repeat readers, WinMain cleanup reader, and global/memory docs already saved with that name.

Open but non-blocking:
- Exact original field spelling is not recovered. `m_savedKeyboardDelay` and `m_savedKeyboardSpeed` are the strongest descriptive source names because the fields store the user's original values to restore, not the active fast-repeat values.
- Exact global linkage is not recovered. First-draft source should use `KeySpeedMgr *g_pKeySpeedMgr = 0;` unless a later header/source split proves `extern` plus one definition.

### Source-Facing Names And Signatures

Recommended source-facing signatures:

```cpp
KeySpeedMgr::KeySpeedMgr();
KeySpeedMgr::~KeySpeedMgr();
void KeySpeedMgr::LoadSystemKeyboardSettings();
void KeySpeedMgr::RestoreSystemKeyboardSettings();
static void __stdcall ApplyKeyboardRepeatSettings(UINT delay, UINT speed);
static void ApplyFastKeyboardRepeatSettings();
// no standalone source function for the scalar deleting destructor
```

Name/signature rationale:
- Constructor/destructor/load/restore use `this` and class fields, so class ownership is stronger than file-local helper ownership.
- Raw setter and fast-repeat helper have no `this`, singleton, or vtable access, so they are file-local helpers in `KeySpeedMgr.cpp`.
- Raw setter has `retn 8`, so the best source signature includes `__stdcall` or equivalent callee-pop convention. Its original name is not proven; `ApplyKeyboardRepeatSettings` is the best descriptive name because the sibling saved label is `ApplyFastKeyboardRepeatSettings`.
- Fast-repeat should be source-facing `void`. The binary leaves the second `SystemParametersInfoW` result in `EAX`, but both callers ignore any return value and the helper is side-effect oriented.
- Restore should be source-facing `void`; all callers ignore the unstable decompiler return artifact.
- Scalar deleting destructor should be modeled as MSVC generated-binary glue from the virtual destructor, not as a source-authored `ScalarDeletingDestructor` method.

### Raw `0x004eff60-0x004eff91` Setter Liveness

Best current conclusion: retained file-local helper, source-shaped and reconstructable, but no live route is currently proven.

Evidence checked:
- Existing live IDA docs and A002 audit report no function object, no code/data xrefs to `0x004eff60`, and no xrefs to `0x004eff91`.
- B010 raw PE scan found no rel32 call/jump route and no little-endian VA pointer hit for `0x004eff60`.
- The body is too structured and semantically aligned with restore/fast-repeat helpers to be padding, data, CRT glue, or random bytes.
- The range is bounded by `0xcc` padding and sits between source-bearing restore and modeled fast-repeat helpers in the `KeySpeedMgr` island.

Policy recommendation:
- Do not leave the old "no recovered original helper name" as a passive blocker.
- Update the page as a retained private helper with descriptive name `ApplyKeyboardRepeatSettings`.
- Enter first-draft C++ despite no caller, because the item is reconstructable, has a valid file emitter, has a complete source-shaped body, and the no-route fact is documented. Keep score below final-audit levels because original source retention and helper spelling are still not proven.

Rejected alternatives:
- Class method: rejected by no `this` access.
- `InputMan` helper: rejected by source neighborhood and no input-message state.
- Runtime/compiler helper: rejected by direct Win32 keyboard-repeat semantics.
- Hidden callback: no pointer/table route found; if a future table route is proven, keep the same helper semantics but update reachability.

### Scalar Deleting Destructor Policy

Best current conclusion: source-declared/generated-binary MSVC scalar deleting destructor wrapper.

Evidence:
- Vtable slot `0x0061c9c8` points to `0x004effc0`; no direct code caller was found.
- Body restores `KeySpeedMgr` vptr, clears `g_pKeySpeedMgr`, calls/chains to `LObject` cleanup, handles delete flags, optionally calls delete wrapper, and has a guard-check path.
- [UID:0002IQ] already carries the source destructor body `g_pKeySpeedMgr = 0;`.

Recommendation:
- Do not write a standalone wrapper implementation.
- Either keep the formal C++ blank with a prose no-body proof, or use B012's comment-only marker if validator/generation policy requires special emitting pages to contain `//`:

```cpp
// Compiler-generated scalar deleting destructor for KeySpeedMgr; source is KeySpeedMgr::~KeySpeedMgr().
```

### Singleton / Vtable / Layout Evidence

- Object allocation size is `0x0c` / 12 bytes (Verified with int_convert.py): vptr at `+0x00`, saved delay at `+0x04`, saved speed at `+0x08`.
- Vtable base `0x0061c9c8` has scalar deleting destructor slot at `+0x00`, inherited `LObject` identity/name slot at `+0x04`, and inherited/default no-op slot at `+0x08`.
- Constructor, ordinary destructor, and scalar wrapper write the `0x0061c9c8` vptr.
- `g_pKeySpeedMgr` is set by the constructor and cleared by destructor variants.
- B014 reports local IDA RTTI shows `Singleton<KeySpeedMgr>` as a base descriptor. Header reconstruction should record this as a real lead, but the exact final base-list/source spelling should be handled in the class/header pass because the empty singleton-base displacement overlaps the saved-field layout evidence.

## First-Draft C++ Recommendations

Do not populate [UID:00018O] aggregate C++; the aggregate should be non-emitting.

Populate exact child/source pages as follows after supervisor acceptance of the relevant reports:

```cpp
KeySpeedMgr::KeySpeedMgr()
{
    g_pKeySpeedMgr = this;
    m_savedKeyboardDelay = UINT(-1);
    m_savedKeyboardSpeed = UINT(-1);
}
```

```cpp
KeySpeedMgr::~KeySpeedMgr()
{
    g_pKeySpeedMgr = 0;
}
```

```cpp
void KeySpeedMgr::LoadSystemKeyboardSettings()
{
    SystemParametersInfoW(SPI_GETKEYBOARDDELAY, 0, &m_savedKeyboardDelay, 0);
    SystemParametersInfoW(SPI_GETKEYBOARDSPEED, 0, &m_savedKeyboardSpeed, 0);
}
```

```cpp
void KeySpeedMgr::RestoreSystemKeyboardSettings()
{
    if (m_savedKeyboardDelay <= 3) {
        SystemParametersInfoW(SPI_SETKEYBOARDDELAY, m_savedKeyboardDelay, 0, SPIF_UPDATEINIFILE);
    }

    if (m_savedKeyboardSpeed <= 31) {
        SystemParametersInfoW(SPI_SETKEYBOARDSPEED, m_savedKeyboardSpeed, 0, SPIF_UPDATEINIFILE);
    }
}
```

```cpp
static void __stdcall ApplyKeyboardRepeatSettings(UINT delay, UINT speed)
{
    if (delay <= 3) {
        SystemParametersInfoW(SPI_SETKEYBOARDDELAY, delay, 0, SPIF_UPDATEINIFILE);
    }

    if (speed <= 31) {
        SystemParametersInfoW(SPI_SETKEYBOARDSPEED, speed, 0, SPIF_UPDATEINIFILE);
    }
}
```

```cpp
static void ApplyFastKeyboardRepeatSettings()
{
    SystemParametersInfoW(SPI_SETKEYBOARDDELAY, 0, 0, SPIF_UPDATEINIFILE);
    SystemParametersInfoW(SPI_SETKEYBOARDSPEED, 31, 0, SPIF_UPDATEINIFILE);
}
```

Support/class/global draft context:

```cpp
KeySpeedMgr *g_pKeySpeedMgr = 0;

class KeySpeedMgr : public LObject {
public:
    KeySpeedMgr();
    virtual ~KeySpeedMgr();

    void LoadSystemKeyboardSettings();
    void RestoreSystemKeyboardSettings();

private:
    UINT m_savedKeyboardDelay;
    UINT m_savedKeyboardSpeed;
};
```

Do not emit explicit vptr stores, base constructor/destructor calls, return-this lowering, delete flags, guard checks, or raw decompiler field names. Record the `Singleton<KeySpeedMgr>` RTTI lead in layout/class notes, but do not force that base list into emitted class code until the header/layout pass decides the exact MSVC empty-base representation.

## Exact Recommended Target Changes

For [UID:00018O] `by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md`:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Keep formal `RECONSTRUCTION_CPP` blank.
- Replace "Generated parent" wording with: "Reviewed non-emitting split/index page over exact KeySpeedMgr children. The class remains the containment owner, but exact child pages carry all source emission or generated-wrapper no-body policy."
- Replace the stale 2026-06-06 change-log sentence "Final C++ remains blank below the 95/95 source gate" with: "Final C++ remains blank because the aggregate itself is not a source-level unit; constructor/load/restore/helpers/destructor pages own formal source and wrapper policy under the current combined-score/emitter gate."
- Update the function table rows with the source-quality names/signatures and field names listed above.
- Add a score rationale explaining `90/92`: exact range and children are fully inventoried; independent raw scan reconfirms routes and no-routes; the only remaining uncertainties are original field/helper spelling and final header base-list style.

## Recommended Support Doc Changes

### `by-class/KeySpeedMgr.md`

- Raise to at least `88/91` after child recommendations are implemented.
- Update "Generated parent" to the current `CANONICAL_OWNER` / `EMITTER_UIDS` wording.
- Add class draft context with constructor, virtual destructor, load/restore methods, and `m_savedKeyboardDelay` / `m_savedKeyboardSpeed`.
- Update method rows:
  - Constructor: source body publishes `g_pKeySpeedMgr` and initializes saved fields to `UINT(-1)`.
  - Load: saves current Windows delay/speed into `m_savedKeyboardDelay` / `m_savedKeyboardSpeed`; ignores API returns.
  - Restore: `void`, range checks `<= 3` and `<= 31`; uses `SPIF_UPDATEINIFILE`.
  - Raw setter: file-local retained helper, not class method.
  - Fast repeat: file-local helper, not class method.
  - Scalar deleting destructor: compiler wrapper only.
- Add RTTI/base-list note: local RTTI reports `Singleton<KeySpeedMgr>` in the hierarchy; final header pass should decide whether to show this base explicitly because object fields remain proven at `+0x04/+0x08`.

### `by-file/KeySpeedMgr.md`

- Keep path `NexusTK/input/`; explicitly reject `Application`, `WinMain`, `InputMan`, and generic `platform` movement for this pass.
- Update proposed contents to mark [UID:00018O] as non-emitting aggregate/index.
- Mark [UID:0002IS] as `static void __stdcall ApplyKeyboardRepeatSettings(UINT delay, UINT speed)` retained/no-live-route helper.
- Mark [UID:00018Q] as `static void ApplyFastKeyboardRepeatSettings()`, source-facing `void`.
- Add source-level global recommendation `KeySpeedMgr *g_pKeySpeedMgr = 0;`.
- Keep [UID:00032A] as related non-owned WinMain cleanup wrapper.

### `by-type/by-struct/KeySpeedMgrLayout.md`

- Keep object size `0x0c` / 12 bytes (Verified with int_convert.py), vptr `+0x00`, saved delay `+0x04`, saved speed `+0x08`.
- Replace generic field wording with final descriptive names `m_savedKeyboardDelay` and `m_savedKeyboardSpeed`.
- Add `Singleton<KeySpeedMgr>` RTTI note as a header-reconstruction lead, not as a reason to move field offsets or alter object size.

### `by-global/g_pKeySpeedMgr.md` and `by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md`

- Add first-draft source declaration/definition recommendation `KeySpeedMgr *g_pKeySpeedMgr = 0;`.
- Preserve WinMain cleanup wrapper as consumer-only, not global owner.

### `by-type/by-vtable/KeySpeedMgrVtable.md` and [UID:00031P] vtable data

- Do not hand-emit vtable bytes.
- Add a note that the scalar deleting destructor page is no-source wrapper evidence; the ordinary destructor page carries source body.

## Score / Metadata Recommendations

| UID | Before | Recommended | Owner/emitter recommendation | C++ recommendation |
| --- | ---: | ---: | --- | --- |
| `00018O` | `84/90` | `90/92` | keep owner `00006Z`, set `RECONSTRUCTABLE:FALSE`, clear emitter | blank aggregate; exact children emit |
| `0002IP` | `84/90` | `88/92` | keep owner/emitter `00006Z` | constructor body |
| `0002IQ` | `87/92` | keep | keep owner/emitter `00006Z` | already emits destructor body |
| `0002IR` | `84/90` | `87/92` | keep owner/emitter `00006Z` | load body |
| `00018P` | `84/90` | `88/92` | keep owner/emitter `00006Z` | restore body |
| `0002IS` | `85/90` | `87/91` | keep owner/emitter `0000KJ` | raw retained setter body, descriptive name |
| `00018Q` | `86/91` | `88/92` | keep owner/emitter `0000KJ` | fast-repeat helper body |
| `0002IT` | `84/90` | `86/91` | keep owner/emitter `00006Z` | no handwritten body; optional comment-only marker |
| `00006Z` | `86/88` | `88/91` | keep owner/emitter `0000KJ` | class declaration draft |
| `0000RB` | `87/90` | `88/91` | keep owner/emitter `0000KJ` | global pointer definition draft |

## IDA Rename / Type / Comment Recommendations

Confidence levels are for IDA labeling/type assistance only, not proof of exact original source spelling.

| Address / item | Recommended IDA name/type/comment | Confidence |
| --- | --- | --- |
| `0x004efea0` | `KeySpeedMgr_Constructor`; source `KeySpeedMgr::KeySpeedMgr()` | high |
| `0x004efee0` | `KeySpeedMgr_Destructor`; source `KeySpeedMgr::~KeySpeedMgr()` | high |
| `0x004eff00` | `KeySpeedMgr_LoadSystemKeyboardSettings`; type `void __thiscall(KeySpeedMgr *)` | high |
| `0x004eff30` | `KeySpeedMgr_RestoreSystemKeyboardSettings`; type `void __thiscall(KeySpeedMgr *)` | high |
| `0x004eff60` | create/label as `ApplyKeyboardRepeatSettings`; type `void __stdcall(UINT delay, UINT speed)`; comment "retained file-local KeySpeedMgr helper; no xrefs found" | medium-high |
| `0x004effa0` | `ApplyFastKeyboardRepeatSettings`; type `void(void)` | high |
| `0x004effc0` | `KeySpeedMgr_ScalarDeletingDestructor`; comment "MSVC scalar deleting destructor wrapper, source is `~KeySpeedMgr`" | high |
| `0x0067ab48` | `g_pKeySpeedMgr`, type `KeySpeedMgr *` | high |
| `KeySpeedMgr + 0x04` | `m_savedKeyboardDelay`, `UINT` | high |
| `KeySpeedMgr + 0x08` | `m_savedKeyboardSpeed`, `UINT` | high |

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` from this B010 pass. If the supervisor implements the aggregate and child recommendations together, replace the KeySpeedMgr block rows with this text:

```markdown
    - [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md) 0x004efea0-0x004f0008 | class-method-cluster index | KeySpeedMgr method/helper aggregate : ignored : 90% : very strong : B010 source-quality pass reclassifies this as a reviewed non-emitting exact split/index over the KeySpeedMgr code island, not a standalone source unit. Independent raw PE route scan and existing live-IDA docs confirm the exact `0x168` aggregate span, all child ranges, all internal `0xcc` padding, constructor/load/restore/fast-repeat callers, no route to the raw setter, scalar deleting destructor vtable route, `g_pKeySpeedMgr` singleton lifecycle, and class/file source placement. Keep `CANONICAL_OWNER:00006Z` for containment, set `RECONSTRUCTABLE:FALSE`, clear emitter, and keep aggregate C++ blank; exact child pages carry source method/helper bodies or generated-wrapper no-body policy.
        - [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) 0x004efea0-0x004efedd | constructor | KeySpeedMgr::KeySpeedMgr : reconstructable : 88% : strong : B014 raw PE/Capstone and IDA-export review confirms exact 61-byte constructor, sole startup caller `0x00463a9a`, `LObject` base-constructor call at `0x004efeaa`, singleton publish to `g_pKeySpeedMgr`, saved keyboard delay/speed sentinel writes, `0x0061c9c8` vptr store, and three-byte `0xcc` successor padding. Replace stale below-95/no-code rationale with first-draft source body `g_pKeySpeedMgr = this; m_savedKeyboardDelay = UINT(-1); m_savedKeyboardSpeed = UINT(-1);`, leaving null-adjust, vptr store, base construction, and return-this as compiler/decompiler mechanics; owner/emitter stay [UID:00006Z] through `NexusTK/input/KeySpeedMgr.cpp`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004efedd-0x004efee0 | padding | KeySpeedMgr internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) 0x004efee0-0x004efef5 | destructor | KeySpeedMgr::~KeySpeedMgr : reconstructable : 87% : strong : Raw PE/Capstone recheck confirms exact 21-byte ordinary destructor body, `0xcc` padding before and after, `0x0061c9c8` vptr store, `g_pKeySpeedMgr` clear, and tail jump to `LObject` cleanup; route scans found no rel32/VA/RVA/raw-pointer refs to the ordinary destructor start, while scalar deletion is reached through vtable slot `0x0061c9c8 -> 0x004effc0`. B003 recommends formal source body `g_pKeySpeedMgr = 0;`, leaving vptr/base cleanup/delete-wrapper behavior to compiler emission.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004efef5-0x004eff00 | padding | KeySpeedMgr internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) 0x004eff00-0x004eff25 | method | KeySpeedMgr::LoadSystemKeyboardSettings : reconstructable : 87% : very strong : B015 source-quality and raw PE checks confirm the exact 0x25-byte load-method body (37 bytes, Verified with int_convert.py), single startup rel32 caller `0x00463aae`, no VA pointer route, two `SystemParametersInfoW` getter calls for `SPI_GETKEYBOARDDELAY` and `SPI_GETKEYBOARDSPEED`, saved field targets `m_savedKeyboardDelay` at `+0x04` and `m_savedKeyboardSpeed` at `+0x08`, ignored Win32 return values with no local range/error branching, clean eleven-byte `0xcc` padding before [UID:00018P], owner/emitter route through [UID:00006Z] -> [UID:0000KJ] `NexusTK/input/KeySpeedMgr.cpp`, and first-draft formal C++ readiness under the active combined-score/emitter gate.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004eff25-0x004eff30 | padding | KeySpeedMgr internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) 0x004eff30-0x004eff5d | method | KeySpeedMgr::RestoreSystemKeyboardSettings : reconstructable : 88% : strong : B007 source-quality pass keeps this as source-bearing KeySpeedMgr method under [UID:00006Z] with emitter route to [UID:0000KJ]; local IDA export, existing live IDA notes, and B010 raw route scan confirm exact `0x2d` body, callers at `0x00464aff`/`0x00466adb`/`0x004ab844`/`0x004f5ee6`, saved keyboard delay at `+0x04` and saved keyboard speed at `+0x08`, range checks delay `<= 3` and speed `<= 31`, direct `SystemParametersInfoW` calls with `SPI_SETKEYBOARDDELAY`/`SPI_SETKEYBOARDSPEED` and `SPIF_UPDATEINIFILE`, ignored decompiler return artifact supporting void source signature, destructor/delete wrappers kept separate, stale 95/95 blank-C++ wording removed, and first-draft C++ ready pending final field spelling consistency.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004eff5d-0x004eff60 | padding | KeySpeedMgr internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) 0x004eff60-0x004eff91 | raw-helper | ApplyKeyboardRepeatSettings : reconstructable : 87% : strong : B010 source-quality pass resolves the raw island as a retained file-local KeySpeedMgr helper, not a class method or runtime/compiler helper. Existing live IDA docs and B010 raw PE scan confirm exact `0x31` body (49 bytes, Verified with int_convert.py), `retn 8` callee-pop signature, no function object, no rel32 caller, no VA pointer route, stack arguments `delay`/`speed`, delay range `<= 3`, speed range `<= 31`, direct `SystemParametersInfoW` calls for `SPI_SETKEYBOARDDELAY`/`SPI_SETKEYBOARDSPEED` with `SPIF_UPDATEINIFILE`, `0xcc` padding on both sides, file owner/emitter [UID:0000KJ], best descriptive source name `static void __stdcall ApplyKeyboardRepeatSettings(UINT delay, UINT speed)`, and first-draft C++ readiness while preserving the no-live-route caveat.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004eff91-0x004effa0 | padding | KeySpeedMgr internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding after the corrected raw setter endpoint.
        - [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md) 0x004effa0-0x004effbd | helper | ApplyFastKeyboardRepeatSettings : reconstructable : 88% : strong : B010 source-quality pass resolves this as a file-local `static void ApplyFastKeyboardRepeatSettings()` helper in [UID:0000KJ] `NexusTK/input/KeySpeedMgr.cpp`. Existing live IDA docs and B010 raw route scan confirm exact `0x1d` body (29 bytes, Verified with int_convert.py), fixed `SystemParametersInfoW(SPI_SETKEYBOARDDELAY, 0, 0, SPIF_UPDATEINIFILE)` and `SystemParametersInfoW(SPI_SETKEYBOARDSPEED, 31, 0, SPIF_UPDATEINIFILE)` calls, ordinary callers `0x00463ab5` and `0x00466a24`, no `this` access, no VA pointer route, ignored EAX return artifact, and first-draft C++ readiness.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004effbd-0x004effc0 | padding | KeySpeedMgr internal alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) 0x004effc0-0x004f0008 | scalar-deleting-destructor | KeySpeedMgr scalar deleting destructor glue : reconstructable : 86% : strong : B012 source-quality review and B010 raw route scan classify this as source-declared/generated-binary KeySpeedMgr scalar deleting destructor glue, not a source-bearing handwritten method. Keep direct owner/emitter [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md) routed through [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) to `NexusTK/input/KeySpeedMgr.cpp`; use a comment-only no-code marker if generation policy requires one while [UID:0002IQ] carries `KeySpeedMgr::~KeySpeedMgr() { g_pKeySpeedMgr = 0; }`. Evidence confirms `sub_4EFFC0` size `0x48`, sole target xref from vtable slot `0x0061c9c8`, vptr restore at `0x004effc6`, `g_pKeySpeedMgr` clear at `0x004effcc`, `LObject` base cleanup, optional delete wrapper only when `(flags & 1) != 0 && (flags & 4) == 0`, guard-check flag-4 path, no direct code callers, and `0xcc` padding before LanguageManLocalization.
```

If only [UID:00018O] is implemented, apply only the first aggregate row and leave child rows for the accepted child-report implementation callbacks.

## Validator Needs

No validator was run because no target/support docs were edited in this report-only pass.

Run from `source-3/project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00018O-KeySpeedMgr-source-quality-removed.md](00018O-KeySpeedMgr-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validate only files actually edited in the implementation callback. `by-memory/-coverage-report.md` remains supervisor-owned while the edit ban is active.

Expected generated-source effect after implementation:
- [UID:00018O] no longer appears as an empty emitter marker.
- Constructor/load/restore/raw setter/fast-repeat helper appear as source bodies if those exact child recommendations are accepted.
- Scalar deleting destructor appears only as blank/no-body proof or a comment-only marker, never as a handwritten wrapper.

## Remaining Open Questions

- Exact original spelling of `m_savedKeyboardDelay`, `m_savedKeyboardSpeed`, and `ApplyKeyboardRepeatSettings` is not proven. The proposed names are descriptive, source-quality names backed by behavior and sibling naming.
- Raw setter source retention remains no-route: no caller/function object/pointer route is currently found. This no longer blocks first-draft source because the helper body is complete, source-shaped, file-local, and reconstructable; it should cap confidence below final audit.
- Exact global linkage for `g_pKeySpeedMgr` is not proven. Use `KeySpeedMgr *g_pKeySpeedMgr = 0;` as first-draft source until header/source split proves otherwise.
- `Singleton<KeySpeedMgr>` RTTI is a strong header-reconstruction lead, but exact base-list spelling is broader class/header work. Do not alter proven field offsets or object size around that uncertainty.
- Current-session IDA MCP was unavailable; this report relies on current docs with prior live-IDA evidence plus B010 raw PE scanning and recent child B reports.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00018O-KeySpeedMgr-source-quality.md`
- Modified: none outside this report.
- Moved to executed: none.

FINISHED report-only checkpoint for [UID:00018O].

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00018O-KeySpeedMgr-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00018O"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018O-KeySpeedMgr-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/00018O-KeySpeedMgr-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
