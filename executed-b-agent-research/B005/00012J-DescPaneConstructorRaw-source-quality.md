** TARGET-REPORT-UID:00012J **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00012J DescPaneConstructorRaw Source-Quality Report

Agent: Agent-B005  
Assignment UID: 00012J  
Target: `0x0049d6f0-0x0049d73c.DescPaneConstructorRaw`  
Report date: 2026-06-18  
Report type: report-only B-preferred source-quality and heuristic/inference pass

## Executive Recommendation

Keep [UID:00012J] as a reconstructable `DescPane::DescPane()` constructor body owned by [UID:00003Q] `DescPane` and emitted through [UID:0000IS] `DescPane` at `NexusTK/ui/controls/DescPane.cpp`. Do not split, rename, or move the target range. Do not directly emit vtable data as C++; treat the observed vtable writes as compiler output for a source-declared class.

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The current blank formal C++ block is no longer justified for this target. The provider interface's original name and the raw setter helper's final source name remain unresolved, but the constructor's source shape is independently recoverable: base `Pane(1)`, clear the description-source pointer, initialize selected index to `-1`, and publish `g_pDescPane`.

Recommended first-draft C++ for the target page:

```cpp
DescPane::DescPane()
    : Pane(1),
      m_pDescriptionSource(NULL),
      m_selectedDescriptionIndex(-1)
{
    g_pDescPane = this;
}
```

`m_pDescriptionSource` and `m_selectedDescriptionIndex` are descriptive reconstruction names, not proven original spellings. If the supervisor prefers non-Hungarian member naming, `m_descriptionSource` is equally defensible, but the constructor should not stay blank solely because the exact original member spellings are unrecovered.

## Assignment And Scope Controls

Re-read inputs required by the assignment were followed: `Supervisor.md`, `Agent-B005/goal.md`, `notes.md`, `by-structure.md`, and `inference_research.md`. The active B-agent mandate is claim-by-claim validation, source-quality owner/emitter ranking, and heuristic/inference resolution rather than deferring all compiler-generated or source-name uncertainty as blockers.

Scope followed:

- Report-only. No by-memory, by-class, by-file, by-type, generated, or coverage docs were edited.
- Existing by-* docs and generated auto-completion/coverage summaries were used as documentation evidence.
- Wave2/wave3 source data was not used.
- Current-session IDA MCP was attempted but unavailable: TCP connect to `127.0.0.1:13337` failed. Existing docs contain prior IDA MCP facts; this pass independently rechecked the raw bytes and static pointer/rel32 patterns from the memory snapshot.

## Current Target State

Current target metadata:

```text
UID:00012J
COMPLETION:84
CONFIDENCE:88
CANONICAL_OWNER:00003Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00003Q
RECONSTRUCTION_CPP: blank
```

Current target doc claims verified or reanalyzed:

- `0x0049d6f0` is a raw constructor-shaped start, not modeled as an IDA function in existing IDA-backed docs.
- Half-open range is `0x0049d6f0-0x0049d73c`, length `0x4c` / 76 bytes.
- Preceding alignment is `0x0049d6ed-0x0049d6f0`, three `cc` bytes.
- Following alignment is `0x0049d73c-0x0049d740`, four `cc` bytes.
- The next child is [UID:00012L] destructor at `0x0049d740-0x0049d769`.
- Constructor calls the `Pane` constructor at `0x00544460` with immediate `1`.
- Constructor installs DescPane vtable bases `0x006189dc`, `0x00618a28`, and `0x00618a58`.
- Constructor clears `this+0xf8`, writes `-1` to `this+0xfc`, and stores `this` to `g_pDescPane` / `0x0069adf8`.
- No direct xrefs to the raw start are documented, and this pass found no raw VA pointer or rel32 route to the raw constructor start in the memory snapshot.

## Raw Byte And Boundary Evidence

Raw constructor neighborhood:

```text
0049d6e0: 45 08 5f 5e 5b 89 08 8b e5 5d c2 08 00 cc cc cc
0049d6f0: 55 8b ec 51 56 8b f1 6a 01 89 75 fc e8 5f 6d 0a
0049d700: 00 c7 06 dc 89 61 00 8b c6 c7 86 a0 00 00 00 28
0049d710: 8a 61 00 c7 86 a4 00 00 00 58 8a 61 00 c7 86 f8
0049d720: 00 00 00 00 00 00 00 c7 86 fc 00 00 00 ff ff ff
0049d730: ff 89 35 f8 ad 69 00 5e 8b e5 5d c3 cc cc cc cc
0049d740: c7 01 dc 89 61 00 c7 81 a0 00 00 00 28 8a 61 00
```

Instruction-level interpretation:

| Address | Bytes / action | Source-quality meaning |
| --- | --- | --- |
| `0x0049d6ed-0x0049d6f0` | `cc cc cc` | Alignment after the predecessor function. |
| `0x0049d6f0` | `55 8b ec 51 56 8b f1` | Standard thiscall constructor prologue; saves `this` in `esi`. |
| `0x0049d6f7` | `6a 01` | Pushes base constructor argument `1`. |
| `0x0049d6fc` | `e8 5f 6d 0a 00` | Calls `0x00544460`, the Pane-family constructor. |
| `0x0049d701` | `c7 06 dc 89 61 00` | Writes primary vtable base `0x006189dc` to `this+0`. |
| `0x0049d707` | `8b c6` | Returns `this` in `eax`. |
| `0x0049d709` | `c7 86 a0 ... 28 8a 61 00` | Writes secondary vtable base `0x00618a28` to `this+0xa0`. |
| `0x0049d713` | `c7 86 a4 ... 58 8a 61 00` | Writes tertiary vtable base `0x00618a58` to `this+0xa4`. |
| `0x0049d71d` | `c7 86 f8 ... 00 00 00 00` | Clears provider/source pointer at `this+0xf8`. |
| `0x0049d727` | `c7 86 fc ... ff ff ff ff` | Sets selected index at `this+0xfc` to `-1`. |
| `0x0049d731` | `89 35 f8 ad 69 00` | Stores `this` to `0x0069adf8` / `g_pDescPane`. |
| `0x0049d737-0x0049d73b` | `5e 8b e5 5d c3` | Constructor epilogue and return. |
| `0x0049d73c-0x0049d740` | `cc cc cc cc` | Alignment before destructor. |

The half-open target range is exactly `0x0049d6f0-0x0049d73c`. There are no embedded `cc` bytes in the constructor body. The four-byte postpad is outside the target and should remain outside it.

## Reachability And Xref Evidence

Existing IDA-backed docs record `lookup_funcs 0x0049d6f0` as `Not a function` and no direct xrefs to the raw start. This pass independently checked raw-memory encodings:

| Pattern | Result |
| --- | --- |
| Raw pointer to `0x0049d6f0` | No hits. |
| Rel32 call/jump target to `0x0049d6f0` | No hits. |
| Raw pointer to setter start `0x0049d780` | No hits. |
| Rel32 call/jump target to setter start `0x0049d780` | No hits. |
| Pointer to `RefreshDescription` `0x0049d7c0` | Hit at vtable slot `0x00618a20`. |
| Pointer to scalar deleting destructor `0x0049d840` | Hit at primary vtable slot `0x006189dc`. |
| Rel32 jumps to scalar deleting destructor `0x0049d840` | Hits from adjustor thunks at `0x0049d824` and `0x0049d82f`. |

Vtable and global reference pattern from raw immediates:

| Target | Raw-memory immediate hits |
| --- | --- |
| `0x006189dc` primary vtable | `0x0049d703`, `0x0049d742`, `0x0049d848` |
| `0x00618a28` secondary vtable | `0x0049d70f`, `0x0049d74c`, `0x0049d852` |
| `0x00618a58` tertiary vtable | `0x0049d719`, `0x0049d756`, `0x0049d85c` |
| `0x0069adf8` singleton storage | `0x0049d733`, `0x0049d75c`, `0x0049d771`, `0x0049d862` |

Best inference: the constructor is a source-authored out-of-line constructor body that the current function recovery does not connect to a static caller. Its direct and indirect static reachability is unproven, but its class identity is strongly anchored by the base constructor call, vtable stores, singleton publish, destructor counterpart, scalar deleting destructor, getter, setter, and refresh island. This caps confidence below final, but it does not justify withholding first-draft C++.

## Aggregate And Child Relationship

[UID:00012K] aggregate `0x0049d6f0-0x0049d89f.DescPane` should continue to contain this constructor as the first child.

| UID | Range | Relationship to 00012J |
| --- | --- | --- |
| `00012J` | `0x0049d6f0-0x0049d73c` | Constructor-shaped raw body; initializes base, fields, vtables, singleton. |
| `00012L` | `0x0049d740-0x0049d769` | Non-deleting destructor; restores same vtables, clears singleton, tail-jumps to Pane cleanup. |
| `00012M` | `0x0049d770-0x0049d776` | `g_pDescPane` getter. |
| `00012N` | `0x0049d780-0x0049d7b0` | Raw setter/update helper for provider pointer and selected index. |
| `00012O` | `0x0049d7c0-0x0049d81e` | Modeled refresh method; consumes `+0xf8/+0xfc` and provider slot `+0x24`. |
| `00012P` | `0x0049d81e-0x0049d834` | Compiler-generated destructor adjustor thunks; non-emitting. |
| `00012Q` | `0x0049d840-0x0049d89f` | Scalar deleting destructor; vtable-reachable and thunk-reached. |

The target's source meaning depends on the whole island, but the range itself should remain a separate constructor child under the aggregate. No split or merge is recommended.

## Vtable And RTTI Boundary Evidence

Raw dwords around the DescPane vtable region:

```text
006189d8: 00646548
006189dc: 0049d840
006189e0: 004f4b10
006189e4: 0041b6c0
006189e8: 004b8e20
006189ec: 0041d680
006189f0: 00544730
006189f4: 00544750
006189f8: 005447a0
006189fc: 00544800
00618a00: 00544a20
00618a04: 00544b80
00618a08: 00544bd0
00618a0c: 00544c70
00618a10: 00544cb0
00618a14: 00544ce0
00618a18: 00544d30
00618a1c: 00544d70
00618a20: 0049d7c0
00618a24: 006465a4
00618a28: 0049d81e
00618a2c: 00544db0
00618a30: 00544dc0
00618a34: 00544dd0
00618a38: 00544de0
00618a3c: 00544df0
00618a40: 00544e00
00618a44: 004a89f0
00618a48: 00544e10
00618a4c: 00544e30
00618a50: 00544e70
00618a54: 006465b8
00618a58: 0049d829
00618a5c: 00544e90
00618a60: 006465cc
```

Adjacent descriptor/string and RTTI boundary:

- Preceding bytes include a UTF-16 `"../"`-style string at `0x006189d0-0x006189d8`, immediately before the primary RTTI locator dword.
- `0x006189d8` is the primary RTTI locator for the DescPane primary view.
- `0x006189dc` is the primary vtable base and the current [UID:0002NA] half-open data page start.
- `0x00618a24` is the secondary view RTTI locator; `0x00618a28` is the secondary vtable base.
- `0x00618a54` is the tertiary view RTTI locator; `0x00618a58` is the tertiary vtable base.
- `0x00618a60` is the next class RTTI locator for `DialogPane`, so the DescPane vtable data must end before it.

Recommendation: keep [UID:0002NA] `0x006189dc-0x00618a60.DescPaneVtableData` as the vtable-entry half-open range under the project convention that vtable data pages start at the vtable base, not at the preceding RTTI locator. No range split or rename is needed. The support doc should clarify that the RTTI locator dwords are boundary evidence but not part of this emitted vtable-entry child.

## Vtable Slot Identities

Primary view `0x006189dc`, 18 slots:

| Slot | Target | Best identity |
| --- | --- | --- |
| `+0x00` | `0x0049d840` | DescPane scalar deleting destructor; source virtual destructor maps here. |
| `+0x04` | `0x004f4b10` | Inherited `LObject::GetRuntimeClass`-style accessor. |
| `+0x08` | `0x0041b6c0` | Inherited/default no-op virtual. |
| `+0x0c` | `0x004b8e20` | Inherited `GrafPort::UpdateRenderRegion` / render-region support. |
| `+0x10` | `0x0041d680` | Inherited/default draw-style no-op slot. |
| `+0x14` | `0x00544730` | `Pane::Show`. |
| `+0x18` | `0x00544750` | `Pane::Hide`. |
| `+0x1c` | `0x005447a0` | `Pane::Repaint`. |
| `+0x20` | `0x00544800` | `Pane::InvalidateRect`; also used by raw setter 00012N. |
| `+0x24` | `0x00544a20` | Inherited `Pane::OnCommand` default/command slot. |
| `+0x28` | `0x00544b80` | `Pane::GetScreenBounds`. |
| `+0x2c` | `0x00544bd0` | `Pane::SetBounds`. |
| `+0x30` | `0x00544c70` | `Pane::AddToLayer`. |
| `+0x34` | `0x00544cb0` | `Pane::InsertInLayer`. |
| `+0x38` | `0x00544ce0` | `Pane::RemoveFromLayer`. |
| `+0x3c` | `0x00544d30` | `Pane::SetPaneOrder` / dispatcher-order helper. |
| `+0x40` | `0x00544d70` | `Pane::UnregisterEventHandler`. |
| `+0x44` | `0x0049d7c0` | `DescPane::RefreshDescription`; only DescPane-specific primary override. |

Secondary view `0x00618a28`, 11 slots:

| Slot | Target | Best identity |
| --- | --- | --- |
| `+0x00` | `0x0049d81e` | Compiler-generated destructor adjustor thunk, subtracts `0xa0` then jumps to scalar deleting destructor. |
| `+0x04` | `0x00544db0` | Inherited Pane/EventHandler bridge/default handler slot. |
| `+0x08` | `0x00544dc0` | Inherited Pane/EventHandler bridge/default handler slot. |
| `+0x0c` | `0x00544dd0` | Inherited Pane/EventHandler bridge/default handler slot. |
| `+0x10` | `0x00544de0` | Inherited Pane/EventHandler bridge/default handler slot. |
| `+0x14` | `0x00544df0` | Inherited Pane/EventHandler bridge/default handler slot. |
| `+0x18` | `0x00544e00` | Inherited Pane/EventHandler bridge/default handler slot. |
| `+0x1c` | `0x004a89f0` | EventHandler dispatcher-forwarding default. |
| `+0x20` | `0x00544e10` | Inherited handler/default slot. |
| `+0x24` | `0x00544e30` | Inherited handler/default slot. |
| `+0x28` | `0x00544e70` | Inherited handler/default slot. |

Tertiary view `0x00618a58`, 2 slots:

| Slot | Target | Best identity |
| --- | --- | --- |
| `+0x00` | `0x0049d829` | Compiler-generated destructor adjustor thunk, subtracts `0xa4` then jumps to scalar deleting destructor. |
| `+0x04` | `0x00544e90` | Inherited tertiary event/update default. |

Compiler-generated names should not remain bare blockers:

- The adjustor thunks [UID:00012P] should stay `RECONSTRUCTABLE:FALSE`, no emitter. They prove secondary/tertiary vtable shape but should not be source-emitted.
- The scalar deleting destructor [UID:00012Q] is compiler-emitted glue for the source virtual destructor. Its existence supports class ownership, not a need for explicit source-level scalar-deleting code.
- The vtable-entry data [UID:0002NA] should stay source-declared/generated-binary support. Source C++ should declare `DescPane` virtuals; the compiler emits vtables and vtable stores.

## Owner, Emitter, And Source Placement Ranking

Final ranking:

| Rank | Candidate | Decision | Evidence |
| ---: | --- | --- | --- |
| 1 | [UID:00003Q] `DescPane` class | Keep as canonical owner/emitter | Constructor writes DescPane vtables, initializes DescPane-only tail fields, publishes DescPane singleton, and sits inside the contiguous DescPane method island. |
| 2 | [UID:0000IS] `DescPane` file | Keep as file owner through class | Existing source tree places it at `NexusTK/ui/controls/DescPane.cpp`; class is a reusable UI control. |
| 3 | `Pane` / `Pane.cpp` | Reject as owner | `Pane` supplies base constructor and inherited virtual slots only. The target's vtables, singleton, tail fields, and refresh method are DescPane-specific. |
| 4 | `DialogPane` / dialog core | Reject | `DialogPane` RTTI begins at `0x00618a60` after the DescPane vtable range; no DialogPane fields or dialog-title/control behavior appear in the constructor. |
| 5 | Feature dialog owners | Reject | No caller/xref fanout ties this constructor to a particular feature dialog. The provider/index pattern is a generic reusable description-pane service. |
| 6 | Generic UI core | Reject as too broad | `Pane` and `DialogPane` fit UI core, but DescPane is a higher-level control. Existing by-project-structure placement under `ui/controls` is more specific and better supported. |

`g_pDescPane` should remain owned by the DescPane file/global support route. Xrefs are confined to the DescPane island: constructor publish, destructor clear, getter read, and scalar destructor clear. The singleton should be named `g_pDescPane`; `dword_69ADF8` is no longer source-quality.

## Source-Quality Names And Field Meanings

Recommended class-local names:

| Offset / entity | Recommended name | Evidence | Rejected alternatives |
| --- | --- | --- | --- |
| `this+0xf8` | `m_pDescriptionSource` | Constructor clears it; raw setter updates it; refresh treats it as an object pointer and calls provider vtable slot `+0x24`. | Generic `void *data`, owner pane, dialog controller, cached text pointer. No lifetime, pane, or text-buffer operations match those meanings. |
| `this+0xfc` | `m_selectedDescriptionIndex` | Constructor initializes to `-1`; raw setter stores caller-provided value; refresh rejects `-1` before provider call. | Count, flags, pane mode, color, cached length. The sentinel and provider call argument identify an index. |
| Provider interface | `DescPaneDescriptionSource` | The pointer source supplies description text for an index into a local 2048-byte buffer. | `PasswordGuard`, feature-dialog owner interface, generic UI core interface. No feature-specific refs exist, and the behavior is DescPane-specific. |
| Provider slot `+0x24` | `GetDescription(int selectedIndex, char *outBuffer)`-style | `RefreshDescription` calls vtable slot `+0x24` with selected index and local buffer. | Setter, command handler, allocation, ownership transfer. The call produces text into a buffer and does not alter ownership. |
| Constructor | `DescPane::DescPane()` | Only implicit `this` is used; immediate `1` is passed to `Pane` base; no other arguments are read. | Factory helper or standalone init routine. Vtable stores, base ctor, and return `this` match a constructor. |

`Pane(1)` should stay as a numeric argument until the `Pane` mode/style enum constant is source-quality. Existing Pane support makes `Pane::InvalidateRect` and base layout strong enough, but the original symbolic name for constructor argument `1` is still unproven.

## Heuristic / Inference Reanalysis And Validation

### Raw Constructor Identity

Evidence checked: target doc, aggregate [UID:00012K], class [UID:00003Q], file [UID:0000IS], layout [UID:0001U3], raw constructor bytes, immediate call to `0x00544460`, vtable stores, field writes, singleton publish, and postpad boundary.

Rejected alternatives:

- Standalone init helper: rejected because it calls the base constructor and installs all three vtable views before field initialization.
- Factory: rejected because no allocation or factory return path exists; it returns `this`.
- Padding/data misclassification: rejected because the bytes decode as a coherent prologue/body/epilogue with no embedded alignment bytes.

Best defensible inference: source constructor `DescPane::DescPane()`.

Impact: owner/emitter stay [UID:00003Q]; source placement stays `ui/controls/DescPane.cpp`; range stays `0x0049d6f0-0x0049d73c`; first-draft C++ should be populated; confidence remains capped by missing direct caller and raw non-function status.

### Raw Start And Reachability

Evidence checked: existing IDA-backed docs saying `0x0049d6f0` is `Not a function` with empty xrefs; raw pointer scan for `0x0049d6f0`; rel32 call/jump scan for `0x0049d6f0`; vtable entries for the rest of the class island; singleton/vtable immediate refs.

Rejected alternatives:

- Direct static caller: no raw pointer, rel32 call, or documented xref supports one.
- Vtable reachability: constructors are not vtable slots; vtable reachability applies to refresh and destructors, not this raw start.
- Dead data: rejected because the body is semantically paired with the destructor/scalar destructor/global lifecycle and class vtables.

Best defensible inference: no static direct or indirect reachability route is currently proven, but the body is source-owned constructor code retained in the binary.

Impact: this is a confidence cap and xref caveat, not an owner/source-placement blocker. It supports `CONFIDENCE:90` rather than final-audit confidence, and it should remain documented in the target page.

### Field Names And Provider Interface

Evidence checked: constructor writes `+0xf8/+0xfc`, setter [UID:00012N] compares and stores both, refresh [UID:00012O] reads both and calls provider vtable slot `+0x24`, layout [UID:0001U3] object size and offsets, class [UID:00003Q] provider-call notes, file [UID:0000IS] source-placement notes.

Rejected alternatives:

- `+0xf8` as a pane, dialog, or owner pointer: rejected because refresh calls it as a provider object and never calls pane methods on it.
- `+0xf8` as a text buffer: rejected because refresh supplies a separate 2048-byte local output buffer.
- `+0xfc` as count, flags, or mode: rejected because it is initialized to `-1` and passed directly to the provider as a selected entry.
- Full provider interface declaration: rejected for now because earlier provider slots are not named and no IDA UDT or source type is present in the checked docs.

Best defensible inference: use descriptive class fields `m_pDescriptionSource` and `m_selectedDescriptionIndex`; use a provisional interface name such as `DescPaneDescriptionSource`; name only the observed provider slot semantically.

Impact: these names are strong enough for first-draft constructor C++ and local class layout comments. They still cap final class/header readiness and should keep class/layout pages below final because the original interface spelling is unproven.

### Constructor Signature And Base Argument

Evidence checked: raw thiscall prologue, only pushed explicit argument `1`, base call to `0x00544460`, no other argument loads, return `eax=this`, Pane support docs.

Rejected alternatives:

- `DescPane::DescPane(Provider *, int)`: rejected because provider/index are initialized to null/sentinel, not loaded from arguments.
- `DescPane::Init(int style)`: rejected because it performs vtable installation and calls the base constructor.
- Named Pane mode constant: not rejected semantically, but withheld as an exact spelling because no source-quality enum constant is proven.

Best defensible inference: `DescPane::DescPane() : Pane(1), ...`.

Impact: formal C++ can be populated with numeric `1`; later support work may replace it with a named `Pane` style/mode constant without changing ownership or range.

### Singleton Name And Storage

Evidence checked: `0x0069adf8` initial storage, constructor store, destructor/scalar-destructor clears, getter read [UID:00012M], global docs [UID:0000QR] and [UID:0001PB].

Rejected alternatives:

- Anonymous `dword_69ADF8`: rejected because the getter/lifecycle pattern and by-global page already identify a singleton.
- Feature-dialog global: rejected because all xrefs are within the DescPane island.
- Owned by aggregate memory only: rejected because source storage belongs in the file-level DescPane module.

Best defensible inference: source global `g_pDescPane`, declared in/near `DescPane.cpp`.

Impact: `g_pDescPane = this;` belongs in first-draft constructor C++; no split or separate feature owner is recommended.

### Vtable Stores And Generated Policy

Evidence checked: constructor vtable writes, destructor/scalar destructor restores, vtable data [UID:0002NA], vtable support [UID:0001XC], raw RTTI boundaries, primary/secondary/tertiary slot inventory.

Rejected alternatives:

- Hand-emitting vtable stores in C++: rejected because vtable stores are compiler output from source-declared polymorphic class constructors/destructors.
- Treating vtable data as non-source noise only: rejected because it is key support evidence for class shape and virtual methods.
- Expanding 0002NA to include RTTI locator dwords: rejected under current page convention and because the vtable-entry range correctly ends before the next class locator.

Best defensible inference: source should declare the class and virtual methods; generated vtable data remains support/doc evidence.

Impact: no `RECONSTRUCTION_CPP` vtable literals for 00012J; no split/rename for vtable data; constructor C++ should omit explicit vtable assignments.

### Source Placement

Evidence checked: class/file docs, proposed source tree, aggregate ownership, rejected owner candidates, singleton xrefs, layout support, vtable support.

Rejected alternatives:

- `ui/core/Pane.cpp`: base behavior only.
- `ui/core/DialogPane.cpp`: next RTTI starts after DescPane; no DialogPane-specific behavior.
- Feature dialog modules: no caller or field evidence.
- Generic shared UI core: too broad relative to `ui/controls/DescPane.cpp` support.

Best defensible inference: `NexusTK/ui/controls/DescPane.cpp` and likely `DescPane.h`.

Impact: owner/emitter unchanged; source placement is strong enough for emission. The report recommends support docs replace vague placement questions with this ranked decision.

### Support-Doc Final-C++ Blockers

Evidence checked: target page blank C++ rationale, class/file/layout pages that say final C++ remains blank pending provider names/raw helper names, active supervisor gate, auto-completion stats `84/88`.

Rejected alternatives:

- Keep target blank until all class/interface names are final: rejected because active B-agent policy requires first-draft C++ when target-specific source shape is defensible and the emitter route clears the current gate.
- Populate a full class/header declaration now: rejected because provider interface spelling, setter helper source name, inherited handler-interface slot names, and Pane mode enum spelling are not final.
- Treat raw non-function status as no-code proof: rejected because constructors may be raw/unmodeled in IDA while still source-owned; here the body is exact and semantically complete.

Best defensible inference: populate only this constructor's formal block now; keep broader class/header and provider interface finalization as support-doc follow-up.

Impact: target score should rise to `88/90`; class/layout docs should no longer use provider names as a blanket reason to suppress this constructor's C++; final class C++ readiness remains partial.

## First-Draft C++ Recommendation

Populate [UID:00012J] formal `RECONSTRUCTION_CPP CODE` with:

```cpp
DescPane::DescPane()
    : Pane(1),
      m_pDescriptionSource(NULL),
      m_selectedDescriptionIndex(-1)
{
    g_pDescPane = this;
}
```

Notes for the supervisor:

- This block represents source behavior, not exact compiler output. The compiler-generated vtable stores at `0x0049d701`, `0x0049d709`, and `0x0049d713` should not appear in the C++ body.
- `Pane(1)` should remain numeric until the source-quality name for Pane constructor mode/style `1` is proven.
- `NULL` is used rather than `nullptr` to match plausible mid-2000s C++ source shape.
- The provider interface declaration itself should remain provisional. The constructor only needs a pointer field initialized to null.

## Metadata, Coverage, And Support-Doc Recommendations

### Target Page 00012J

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00003Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00003Q
```

Replace the current Status sentence:

```text
Final C++ is intentionally blank because this raw constructor should be emitted with the coordinated `DescPane` class once provider/interface names are finalized.
```

with:

```text
Formal first-draft C++ is ready for this constructor: the source behavior is `DescPane::DescPane() : Pane(1), m_pDescriptionSource(NULL), m_selectedDescriptionIndex(-1) { g_pDescPane = this; }`. Provider/interface original spellings and the raw setter helper name remain provisional class-level blockers, but they do not block this constructor body.
```

Add or preserve a reachability caveat:

```text
The raw constructor start still has no proven direct caller, raw VA pointer, or rel32 call/jump reference in the checked evidence. This limits confidence below final-audit level but does not change ownership, range, or first-draft C++ readiness.
```

### by-memory/-coverage-report.md

Do not edit directly under this assignment. If the supervisor accepts the scoring change, replace the existing [UID:00012J] row at line 1277 context with:

```text
    - [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md) : reconstructable : 88% : very-strong : Raw `DescPane` constructor body; B005 2026-06-18 source-quality pass confirms exact 76-byte half-open range, three-byte prepad, four-byte postpad, `Pane(1)` base construction, vtable stores to `0x006189dc`/`0x00618a28`/`0x00618a58`, provider/source clear at `+0xf8`, selected-index sentinel `-1` at `+0xfc`, singleton publish to `g_pDescPane`/`0x0069adf8`, no pointer or rel32 route to the raw start, unchanged owner/emitter route through `ui/controls/DescPane.cpp`, and first-draft constructor C++ readiness.
```

Neighbor rows also look stale relative to current docs. If the supervisor is updating this block, these exact replacements are recommended:

```text
    - [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md) : reconstructable : 86% : strong : DescPane class-method aggregate with exact constructor/destructor/getter/source-index setter/refresh/thunk/scalar-destructor split, singleton lifecycle through `g_pDescPane`, three-view vtables, provider/index tail at `+0xf8/+0xfc`, and reusable `ui/controls/DescPane.cpp` owner route; remaining caveats are raw-start reachability and final provider/interface spelling.
```

```text
    - [UID:00012N][0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md) : reconstructable : 85% : strong : Raw `DescPane` source/index update helper; docs confirm exact raw boundary, no-function/no-xref/no-pointer-encoding status, provider/source and selected-index fields at `+0xf8/+0xfc`, conditional stores, `Pane::InvalidateRect` dispatch through primary slot `+0x20` with bounds at `this+0x44`, and refresh consumer behavior; final setter/provider-interface spelling remains provisional.
```

```text
    - [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) : ignored : 88% : very-strong : Compiler-generated secondary/tertiary destructor adjustor thunks; docs and raw bytes confirm two 0x0b-byte bodies subtracting `0xa0`/`0xa4` and jumping to the scalar deleting destructor, vtable refs at `0x00618a28`/`0x00618a58`, and no handwritten source emission.
```

### project-level/-auto-completion-stats.md

If metadata is accepted, the two current `00012J` rows should update from:

```text
| `00012J` | 84 | 88 | 86.0 | `by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md` |
```

to:

```text
| `00012J` | 88 | 90 | 89.0 | `by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md` |
```

### Support Docs

Recommended support-doc changes, report-only:

- [UID:00003Q] `DescPane` class: revise the statement that final C++ remains blank because constructor and setter are raw and provider names are not final. Target-specific constructor C++ is ready; broader class/header finalization remains blocked only by provider interface spelling, setter helper source name, inherited handler-interface slot names, and Pane mode enum spelling.
- [UID:0000IS] `DescPane` file: keep `NexusTK/ui/controls/DescPane.cpp`; replace placement caveats with the ranked owner decision above. The file page can say constructor and getter/source lifecycle are ready for first-draft emission, while full class header remains provisional.
- [UID:0001U3] `DescPaneLayout`: keep object size `0x100` and offsets `+0xf8/+0xfc`; change "final C++ remains blank" language to "field names are descriptive and sufficient for first-draft constructor C++, but exact original provider-interface spelling is unresolved."
- [UID:0001XC] `DescPaneVtables` and [UID:0002NA] `DescPaneVtableData`: keep source-declared/generated-vtable policy; do not emit vtable data manually. Update stale assignment-gate wording in [UID:0002NA] that still cites older class/file scores; current support route is class `86/88`, file `86/87`, vtable support `86/90`.
- [UID:0000QR] `g_pDescPane` and [UID:0001PB] memory storage: keep source-owner route through `DescPane.cpp`; if formal C++ is added for constructor/destructors/getter, prefer `g_pDescPane` over `dword_69ADF8`.

## Remaining Blockers After This Pass

These are not bare blockers; each has a decision and impact:

| Issue | Evidence checked | Decision | Impact |
| --- | --- | --- | --- |
| No direct constructor caller | Existing IDA-backed docs plus raw pointer/rel32 scans | Keep documented as no proven direct or indirect static route | Caps confidence below final; no owner/range/C++ block. |
| Raw non-function start | Target/class/file/layout docs | Keep target as raw constructor-shaped method | Naming remains descriptive, but first-draft C++ is justified. |
| Provider interface original name | Class/layout/file docs and refresh provider call | Use provisional `DescPaneDescriptionSource`; do not declare full interface yet | Blocks final header/interface, not constructor C++. |
| Field original spellings | Constructor/setter/refresh evidence | Use descriptive `m_pDescriptionSource` and `m_selectedDescriptionIndex` | Allows constructor C++; caps final exactness. |
| Setter helper source name | [UID:00012N] raw setter and refresh consumer | Keep provisional source/index update helper | Does not block constructor; blocks full class API readiness. |
| Pane mode/style constant for `1` | Constructor bytes and Pane support docs | Emit `Pane(1)` until enum constant is proven | Minor readability blocker only. |
| Inherited secondary/tertiary handler slot names | Vtable support docs and EventHandler defaults | Keep as inherited handler/default slots | Does not affect constructor; affects vtable/class finality only. |
| Current-session IDA MCP unavailable | TCP connect to `127.0.0.1:13337` failed | Use existing IDA-backed docs plus raw memory verification | Mentioned as confidence limitation for this report, not a target blocker. |

## Final C++ Readiness

Target-specific readiness: ready for first-draft C++.

Class-wide readiness: partial. The constructor, destructor lifecycle, singleton getter, and refresh behavior are source-shaped well enough for staged reconstruction. A polished final class/header should wait for source-quality provider interface spelling, setter helper name, Pane mode constant, and inherited handler slot names.

Score effect:

- Current `84/88` reflects strong raw evidence but old no-code posture.
- Recommended `88/90` reflects exact raw range, stronger negative reachability checks, resolved source-owner ranking, support-doc cross-checks, and target-specific C++ readiness.
- Do not score higher yet because direct constructor reachability is still unproven, current-session MCP was unavailable, and exact provider/interface/member spellings remain inferred.

## Files Changed By This Report

Created only:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\00012J-DescPaneConstructorRaw-source-quality.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00012J-DescPaneConstructorRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"00012J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
