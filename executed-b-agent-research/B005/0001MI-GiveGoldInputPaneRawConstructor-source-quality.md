** TARGET-REPORT-UID:0001MI **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001MI GiveGoldInputPaneRawConstructor Source-Quality Report

Agent: B005  
Assignment id: `B005-report-0001MI-give-gold-input-pane-raw-constructor-20260625`  
Target: [UID:0001MI] `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`  
Required report path: `tools/leaser/Agents/Agent-B005/research/0001MI-GiveGoldInputPaneRawConstructor-source-quality.md`

## Executive Recommendation

Update [UID:0001MI] from `COMPLETION:86`, `CONFIDENCE:89` to `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:00005T`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005T`, and blank `EMITTER_POSITION_OPTIONAL`.

Populate the target's formal `RECONSTRUCTION_CPP CODE` block with the exact constructor initializer below. The old "C++ blank under the 95+ gate" and retained-no-route no-code conclusion is now stale under the current Rule 26 / active combined-score emitter gate and under accepted same-file raw-constructor precedents. The no-function/no-start-xref/no-pointer evidence remains valid, but it is a confidence cap and callgraph caveat, not a blocker to first-draft constructor source.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
GiveGoldInputPane::GiveGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetLocalizedString(0x2b))
{
}
```

This source block represents the source-level constructor operation: pass the localized prompt for id `0x2b` into the `NumberInputPane` base constructor. It intentionally omits the three vptr stores because those are compiler output from the derived class declaration/layout, not handwritten source statements.

Recommended replacement `Item Summary`:

```text
Source-ready retained GiveGoldInputPane constructor; current MCP session `80de0a67` confirms exact `0x40` bytes, prompt id `0x2b` through `g_pLanguageMan->GetLocalizedString`, `NumberInputPane` base construction, compiler-emitted vptr stores at `+0/+0xa0/+0xa4`, matching live `GiveInputPane` inline construction, and no raw-start xrefs or pointer hits; formal first-draft constructor C++ is ready while no-route and prompt-id spelling remain confidence caps.
```

## Current Target State

Active source page read from `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00005T`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00005T`
- blank formal C++
- `Item Summary` still says the constructor's C++ is blank under the stale `95+` gate.

The body text already preserves much valid evidence: exact `0x40` / 64-byte size, prompt id `0x2b` / 43, `g_pLanguageMan` lookup, `NumberInputPane` base construction, vtable stores `0x00630048`, `0x00630098`, and `0x006300c8`, no direct start xref, no pointer-pattern hits from earlier passes, clean `0xcc` pre-padding, and the inline construction mirror in [UID:00005U] `GiveInputPane`.

Stale or now-contradictory target language:

- the header says C++ remains blank under the `95+` gate;
- reconstruction notes say "Do not emit that constructor body from this raw memory page yet";
- the B015-era no-code proof treats the no-route retained raw constructor as a body blocker rather than a confidence cap;
- the draft source shape uses `kGiveGoldPromptStringId` despite no recovered enum/source spelling.

## Evidence Checked

### Project And Workflow

- Read the active user assignment and `tools/leaser/Agents/Agent-B005/goal.md`.
- Used the project-level `ntk-b-agent-workflow` skill.
- Read the B-agent workflow and Rule 26 references, including the current reconstruction-code gate: `RECONSTRUCTABLE:TRUE`, nonblank emitter route to generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
- Read `by-structure.md` scoring, owner/emitter, MCP, and `RECONSTRUCTION_CPP CODE` rules.

### Active Documentation

Read-only docs checked:

- target [UID:0001MI] `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`;
- [UID:00005T] `by-class/GiveGoldInputPane.md`;
- [UID:0000KC] `by-file/ItemActionInputPanes.md`;
- [UID:0001MG] `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`;
- [UID:00005U] `by-class/GiveInputPane.md`;
- [UID:00009L] `by-class/NumberInputPane.md`;
- [UID:0001XU] `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`;
- [UID:0000RC] `by-global/g_pLanguageMan.md`;
- [UID:000361] `by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md`;
- [UID:0003MW] `by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md`;
- sibling/precedent raw constructors [UID:0001M0] `TakeOffInputPaneRawConstructor`, [UID:0001M5] `ChangeItemSlotInputPaneRawConstructor`, and [UID:0001MH] `DropGoldInputPaneRawConstructor`;
- supervisor-owned manual `by-memory/-coverage-report.md` row for [UID:0001MI], read-only.

Generated/read-only leads checked:

- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` currently has accepted constructor C++ for [UID:0001M5] and [UID:0001M0], but still carries [UID:0001MI] as a stale `74/84` empty emitter marker.
- `auto-generated/-ag-coverage-report-by-memory.md` and `auto-generated/-ag-research-tracker.md` still have stale [UID:0001MI] `74/84` / `95+ gate` state from generated/manual defaults.
- `by-memory/-coverage-report.md` line 2959 still contains a stale [UID:0001MI] `74% : strong` row with "C++ blank under the 95+ gate."

No by-* docs, generated files, coverage reports, validator state/cache, project-level files, leases, or IDA DB edits were made during this report-only pass.

### MCP Provenance

IDA MCP endpoint: `http://127.0.0.1:13337/mcp`.

JSON-RPC `initialize` and `tools/list` succeeded. `idb_list` reported active session:

- session id: `80de0a67`
- input path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- filename: `NexusTK.exe.i64`
- backend: `worker`
- active/owned/adopted: true
- pid / worker_pid: `26892`

`server_health database=80de0a67` returned:

- status: `ok`
- module: `NexusTK.exe`
- input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- imagebase: `0x400000`
- Hex-Rays ready: true
- strings cache ready: true
- strings cache size: `2067`

MCP tools used: `lookup_funcs`, `insn_query`, `get_bytes`, `xrefs_to`, `find_bytes`, `find`, `get_int`, `callees`, and `decompile`. No MCP mutation tools were used.

### Numeric Conversion Checks

`tools/int_convert.py` was run from `source-3/project-documentation`:

- `0x2b` = 43 (Verified with `int_convert.py`)
- `0x40` = 64 (Verified with `int_convert.py`)
- `0x108` = 264 (Verified with `int_convert.py`)
- `0xa0` = 160 (Verified with `int_convert.py`)
- `0xa4` = 164 (Verified with `int_convert.py`)
- `0x9a` = 154 (Verified with `int_convert.py`)
- `0x173` = 371 (Verified with `int_convert.py`)

## Current MCP Findings

### Function Map And Boundaries

`lookup_funcs` in session `80de0a67`:

- `0x005b5223`: not a function.
- `0x005b5230`: not a function.
- `0x005b52ac`: not a function.
- `0x005b52b0`: not a function.
- `0x005b52ef`: not a function.
- `0x005b52f0`: `sub_5B52F0`, size `0x9a` / 154 bytes (Verified with `int_convert.py`).
- `0x004f27a0`: `sub_4F27A0`, size `0x73`.
- `0x004f0350`: `sub_4F0350`, size `0x22`.
- `0x005b50b0`: `sub_5B50B0`, size `0x173` / 371 bytes (Verified with `int_convert.py`).

`get_bytes` confirms:

- `0x005b52ac-0x005b52b0` is `cc cc cc cc`, four bytes of alignment padding.
- `0x005b52b0-0x005b52f0` is exactly 64 bytes (Verified with `int_convert.py`) ending in `5e 8b e5 5d c3`.
- `0x005b52f0` begins the modeled submit method prologue `55 8b ec 81 ec ...`.

This validates the target half-open range and excludes the preceding give-item helper and following submit method from the constructor page.

### Raw Constructor Instruction Sequence

`insn_query` over `0x005b52b0-0x005b52f0` decoded 20 instructions, all outside an IDA function object:

| Address | Instruction | Meaning |
| --- | --- | --- |
| `0x005b52b0` | `push ebp` | thiscall constructor-shaped prologue. |
| `0x005b52b1` | `mov ebp, esp` | frame setup. |
| `0x005b52b3` | `push ecx` | local/scratch slot. |
| `0x005b52b4` | `push esi` | preserve `esi`. |
| `0x005b52b5` | `mov esi, ecx` | save `this`. |
| `0x005b52b7` | `mov ecx, dword_67A750` | load [UID:0000RC] `g_pLanguageMan`. |
| `0x005b52bd` | `push 2Bh` | pass prompt id `0x2b` / 43 (Verified with `int_convert.py`). |
| `0x005b52bf` | `mov [ebp-4], esi` | save `this`. |
| `0x005b52c2` | `call sub_4F0350` | call `LanguageMan::GetLocalizedString` / raw `sub_4F0350`. |
| `0x005b52c7` | `push eax` | pass returned `const wchar_t *` prompt. |
| `0x005b52c8` | `mov ecx, esi` | restore `this` for base constructor. |
| `0x005b52ca` | `call sub_4F27A0` | call `NumberInputPane::NumberInputPane(const wchar_t *)`. |
| `0x005b52cf` | `mov [esi], offset ??_7GiveGoldInputPane@@6B@` | compiler vptr store at `this+0`. |
| `0x005b52d5` | `mov eax, esi` | constructor return value. |
| `0x005b52d7` | `mov [esi+0A0h], offset ??_7GiveGoldInputPane@@6B@_0` | compiler secondary vptr store at `this+0xa0` / 160 (Verified with `int_convert.py`). |
| `0x005b52e1` | `mov [esi+0A4h], offset ??_7GiveGoldInputPane@@6B@_1` | compiler tertiary vptr store at `this+0xa4` / 164 (Verified with `int_convert.py`). |
| `0x005b52eb` | `pop esi` | epilogue. |
| `0x005b52ec` | `mov esp, ebp` | epilogue. |
| `0x005b52ee` | `pop ebp` | epilogue. |
| `0x005b52ef` | `retn` | plain thiscall constructor return. |

This is source-real constructor evidence. The source-facing body is not a packet helper, vtable object, padding, or pure compiler artifact; it is the derived constructor shape for `GiveGoldInputPane`.

### Base Constructor And Language Lookup

`decompile 0x004f0350`:

- returns `L"Invalid String ID"` if the id is out of range;
- otherwise returns `*(const wchar_t **)(this[1] + 4 * id)`;
- supports the source-facing helper name `LanguageMan::GetLocalizedString` used by [UID:0000RC] and [UID:00040P].

`decompile 0x004f27a0`:

- calls `sub_4F1C00(this, prompt)`, the `LineInputPane` base constructor;
- installs `NumberInputPane` primary/secondary/tertiary vtables;
- disables/edit-configures the child at `this[63]` through `sub_544EA0(child, 0)`;
- returns `this`.

For this target, `sub_4F27A0` is best represented as `NumberInputPane::NumberInputPane(const wchar_t *)`; `sub_4F0350` is best represented in the formal block as `g_pLanguageMan->GetLocalizedString(0x2b)`. `GetString(kGiveGoldPromptStringId)` remains a reasonable prose/source-style future alias, but the constant name is not recovered and should not be used as the formal code's only evidence-backed spelling.

### Live Inline Construction Mirror

`decompile 0x005b50b0` (`GiveInputPane::OnConfirmInput`) confirms the active gold branch:

- after reading one input character, it branches on `0x5c` (`\`) or `0x2f` (`/`);
- allocates `0x108` / 264 bytes (Verified with `int_convert.py`);
- reads `dword_67A750` / `g_pLanguageMan`;
- calls `sub_4F0350(..., 43)` with the same prompt id `0x2b` / 43 (Verified with `int_convert.py`);
- calls `sub_4F27A0(v6, prompt)`, the same `NumberInputPane` constructor;
- stores `GiveGoldInputPane` vtables at the same three views:
  - primary store at `0x005b51f8` for `0x00630048`;
  - secondary store at `0x005b51fe` for `0x00630098`;
  - tertiary store at `0x005b5208` for `0x006300c8`.

This proves the constructor source shape and class identity even though it does not create a direct raw-start route to `0x005b52b0`. The source model is an ordinary `GiveGoldInputPane` constructor initializer, mirrored inline by the creator path after compiler/codegen decisions.

### Xrefs, Vtables, And Route-Negative Evidence

`xrefs_to` in session `80de0a67`:

- `0x005b52b0`: zero xrefs.
- `0x005b52f0`: one data xref at `0x00630090`, the primary vtable submit/action slot.
- `0x00630048`: two data refs, `0x005b51f8` in `sub_5B50B0` and `0x005b52cf` in the raw constructor island.
- `0x00630098`: two data refs, `0x005b51fe` in `sub_5B50B0` and `0x005b52d7` in the raw constructor island.
- `0x006300c8`: two data refs, `0x005b5208` in `sub_5B50B0` and `0x005b52e1` in the raw constructor island.
- `0x004f27a0`: four code xrefs, including the DropGold and GiveGold raw constructor islands and the live Drop/Give inline creators.

`find_bytes`:

- pointer pattern `b0 52 5b 00` for raw constructor start `0x005b52b0`: zero matches.
- pointer pattern `f0 52 5b 00` for submit method `0x005b52f0`: one match at `0x00630090`.
- vtable immediate `48 00 63 00`: two matches, `0x005b51fa` and `0x005b52d1`.
- vtable immediate `98 00 63 00`: two matches, `0x005b5204` and `0x005b52dd`.
- vtable immediate `c8 00 63 00`: two matches, `0x005b520e` and `0x005b52e7`.

`find type=immediate`:

- immediate `0x005b52b0`: zero matches.
- immediate `0x00630048`: `0x005b51f8`, `0x005b52cf`.
- immediate `0x00630098`: `0x005b51fe`, `0x005b52d7`.
- immediate `0x006300c8`: `0x005b5208`, `0x005b52e1`.

`get_int` confirms vtable slot data:

- dword at `0x00630090` is `0x005b52f0`, the vtable-routed submit method.
- dwords at `0x00630048`, `0x00630098`, and `0x006300c8` point to the expected destructor/adjustor entries for the class view tables; they are vtable data, not raw constructor callers.

These negatives must be preserved. They block using `0x005b52b0` as an IDA callgraph anchor or claiming an active direct-call route. They do not block formal constructor source once the exact constructor shape, direct owner/emitter route, inline construction mirror, base constructor, prompt lookup, vtable identity, and local raw-constructor precedent all support it.

### Adjacent Submit And Packet Helper Context

`callees 0x005b52f0` confirms the submit method calls:

- `0x004f2300` text copy;
- `0x004944f0` wide scanf wrapper;
- `0x00575380` `PacketBufferWriteUInt8`;
- `0x005753f0` `PacketBufferWriteUInt32BE`;
- `0x00574bb0` `QueueAndSendPacket`;
- security-cookie check.

[UID:0003MW] `SendGiveGoldPacketRaw` is already sufficiently updated at `86/89`. It has the correct source-facing helper name `SendGiveGoldPacket(unsigned int amount)`, current `g_pUserPane +0x3ec0` / `m_itemCommandBusy`, `g_packetSender`, `QueueAndSendPacket`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, local-only terminator, send length `5`, and no-route C++ blocker for the helper. It should be checked during implementation but no routine edit is expected unless a contradiction is introduced.

## Heuristic / Inference Reanalysis And Validation

### Raw Constructor Versus Active Route

Decision: represent [UID:0001MI] as `GiveGoldInputPane::GiveGoldInputPane()` first-draft constructor source, with no-route evidence retained as a confidence cap.

Evidence:

- raw island is exactly constructor-shaped and returns `this`;
- prompt id and base constructor match the live inline creator;
- installed vtables uniquely identify `GiveGoldInputPane`;
- owner/emitter route through [UID:00005T] `GiveGoldInputPane` and [UID:0000KC] `ItemActionInputPanes` is already valid;
- same-file accepted raw-constructor precedents now emit first-draft constructors despite no raw-start route.

Rejected alternatives:

- Keep blank solely because there is no IDA function object: rejected under current Rule 26 and accepted [UID:0001M0]/[UID:0001M5] precedents.
- Keep blank solely because there is no direct xref/pointer to `0x005b52b0`: rejected for the same reason; it remains a route caveat.
- Treat the raw island as a packet helper: rejected because it calls `NumberInputPane` and installs class vtables, with no packet writes.
- Treat it as `NumberInputPane`-owned: rejected because `NumberInputPane` is only the base constructor dependency.
- Treat it as compiler-only with no source value: rejected because it expresses a class-specific source constructor initializer. Only the vptr stores are compiler-generated.
- Move ownership to [UID:00005U] `GiveInputPane`: rejected because `GiveInputPane` is the creator/dispatcher. It proves the inline mirror but does not own the derived class implementation.

### Source-Facing Prompt Name

Decision: use literal `0x2b` in formal C++ and document descriptive names only in prose.

`0x2b` / 43 is exact and current (Verified with `int_convert.py`). The source-facing prompt role is "give-gold amount prompt." Names such as `kGiveGoldPromptStringId` or `LANG_PROMPT_GIVE_GOLD_AMOUNT` remain useful descriptive aliases but are not recovered original enum names. Using an inferred constant in the formal block would overstate source-name certainty. The accepted `TakeOffInputPane` formal block already uses `g_pLanguageMan->GetLocalizedString(0x22)`, so `g_pLanguageMan->GetLocalizedString(0x2b)` is a defensible local style for this constructor.

### `sub_4F0350` Source API

Decision: represent `sub_4F0350` as `g_pLanguageMan->GetLocalizedString(0x2b)` in this formal block.

Evidence:

- [UID:0000RC] names the singleton `g_pLanguageMan`.
- [UID:00040P] names the exact lookup child `LanguageManGetLocalizedString`.
- MCP decompilation shows bounds-checked string-id lookup returning `const wchar_t *`.
- The target and inline creator both pass id `0x2b`.

Rejected alternative: `g_pLanguageMan->GetString(kGiveGoldPromptStringId)` in the formal block. It is source-plausible but less evidence-backed here because the enum/constant name is not recovered and the `LanguageManGetLocalizedString` child already gives a concrete source-facing helper spelling. Mention `GetString` only as an existing support-page style caveat if broader language-manager naming is later standardized.

### Vtable Stores

Decision: document vtable stores in prose/evidence, not in formal C++.

The raw bytes write `0x00630048`, `0x00630098`, and `0x006300c8` at `this+0`, `this+0xa0`, and `this+0xa4`; the live inline creator writes the same vtables. These are compiler-emitted consequences of the derived class declaration and base layout. The formal source constructor should not hand-write vtable assignments.

### Score-Limiting Evidence

No-function/no-xref/no-pointer evidence is valid and should remain visible:

- IDA still does not model `0x005b52b0` as a function.
- `xrefs_to 0x005b52b0` is empty.
- current MCP pointer-pattern and immediate-route searches found no raw-start route.
- the active construction route is currently an inline branch in `GiveInputPane::OnConfirmInput`.

Impact:

- do not claim a direct call route;
- do not use the raw start as an active IDA function boundary;
- keep confidence below final audit;
- do not block source-level constructor C++ because the constructor source shape and emitter route are now sufficiently supported.

### Historical/Stale Assumptions

Stale assumptions to explicitly supersede during implementation:

- "C++ blank under the 95+ gate": stale. The current gate is combined score above 85 with a valid emitter route, plus target-specific source-readiness.
- "Retained/no-route constructor body means no formal C++": stale for this same source-family after [UID:0001M0] and [UID:0001M5] accepted implementations.
- B015's negative evidence remains useful, but B015's target-change direction for [UID:0001MI] predates the accepted raw-constructor C++ precedent and should no longer be treated as a no-code proof.
- Generated `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` and generated coverage rows are stale for [UID:0001MI] because the supervisor-owned manual `by-memory/-coverage-report.md` row still says `74%` and `95+ gate`.

No Wave2/Wave3 source data was used as authoritative evidence. Existing `simroot_v2` and generated files were treated only as stale/generated leads.

## Ownership And Source Placement

Ranked owner/source candidates:

1. [UID:00005T] `GiveGoldInputPane` as canonical owner/emitter for [UID:0001MI] - accepted. The raw body is a class constructor, installs `GiveGoldInputPane` vtables, and belongs to the derived class.
2. [UID:0000KC] `ItemActionInputPanes` as file route - accepted through the class page. The item-action prompt family, nearby Drop/Give panes, and `NexusTK/ui/dialogs/ItemActionInputPanes.cpp` generated route support this placement.
3. [UID:00005U] `GiveInputPane` - rejected as direct owner. It is the creator/dispatcher branch that mirrors construction, not the derived class owner.
4. [UID:00009L] `NumberInputPane` / [UID:0000K7] `InputPanes` - rejected as direct owner. They own the reusable numeric base constructor.
5. [UID:0000RC] `g_pLanguageMan` / [UID:0000KK] `LanguageMan` - rejected as direct owner. They provide the localized prompt string only.
6. Socket/PacketBuffer/UserPane/global state pages - rejected as direct owner. They matter for the submit/packet helper, not this constructor.

No split, rename, or new child is required for the constructor target. The existing half-open `0x005b52b0-0x005b52f0` page is the correct range. A future exact child for `0x005b52f0-0x005b538a` may still be useful for submit-method C++, but that is outside this constructor implementation.

## Score And Metadata Recommendation

Target before:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00005T`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00005T`
- blank formal C++

Recommended after:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00005T`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00005T`
- blank `EMITTER_POSITION_OPTIONAL`
- formal constructor C++ populated with the exact block above.

Rationale:

- Completion rises because this pass resolves the stale formal-C++ blocker, chooses the formal helper/prompt spelling, records current MCP session `80de0a67` evidence, ties the constructor to accepted same-file raw-constructor precedents, and identifies exact support-doc and coverage-row corrections.
- Confidence rises because current MCP reconfirms exact body instructions, base constructor, language lookup, inline mirror, vtable identity, function-map boundary, and raw-start route negatives.
- Scores stay below final audit because the raw start still has no direct xref/pointer route, IDA still has no function object at `0x005b52b0`, and the final localized-string enum/source constant name is unrecovered.

## Recommended Target Changes

For [UID:0001MI] `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`:

- Set `COMPLETION:88`, `CONFIDENCE:90`.
- Preserve `CANONICAL_OWNER:00005T`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005T`, and blank `EMITTER_POSITION_OPTIONAL`.
- Replace the `Item Summary` with the exact summary in this report.
- Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report.
- Update Status/Rebuild handling to "retained raw constructor-shaped class body with formal first-draft source C++; not an IDA function object."
- Replace "Do not emit" and "95+ gate" wording with the current conclusion: formal constructor C++ is ready; no-route evidence remains a confidence cap.
- Document current MCP session `80de0a67` evidence at report-level detail:
  - `lookup_funcs` no function at raw start and modeled submit at `0x005b52f0`;
  - instruction query over exact `0x005b52b0-0x005b52f0`;
  - `get_bytes` padding/body boundary;
  - `xrefs_to` zero raw-start refs and vtable/submit refs;
  - `find_bytes` zero raw-start pointer hits and vtable immediate matches;
  - `decompile 0x005b50b0`, `0x004f27a0`, and `0x004f0350`.
- Preserve B015/A005 negative evidence as audit support, but explicitly supersede B015's no-code/retained-no-route target-change direction.
- Replace `kGiveGoldPromptStringId` in the source block with literal `0x2b`; keep descriptive prompt constants only as inferred prose aliases.

## Recommended Support Changes

### [UID:00005T] `by-class/GiveGoldInputPane.md`

Update method/source-quality notes:

- [UID:0001MI] now has formal first-draft constructor C++.
- Preserve that `GiveInputPane::OnConfirmInput` is the live inline creator route and does not transfer ownership to `GiveInputPane`.
- Preserve no-function/no-xref/no-pointer evidence as confidence caps, not C++ blockers.
- Keep class-page formal C++ blank unless a separate declaration pass assembles class declarations; this report only recommends constructor C++ on the exact by-memory constructor page.
- Replace stale "raw constructor no-code" or `95+` wording for [UID:0001MI].
- Keep [UID:0003MW] raw helper no-code unless a caller/source route appears; that helper is a file-scope packet helper, not the constructor.

### [UID:0000KC] `by-file/ItemActionInputPanes.md`

Update the `GiveGoldInputPane` proposed-contents row and boundary/change notes:

- record [UID:0001MI] as first-draft populated like accepted [UID:0001M0] and [UID:0001M5];
- preserve `0x00630090 -> 0x005b52f0` as the active submit route;
- preserve the no-direct-call caveat for the raw constructor start;
- replace B015-era "retained/no-route no-code" for the constructor with "no-route confidence cap, formal constructor C++ ready";
- keep `NexusTK/ui/dialogs/ItemActionInputPanes.cpp` as the source route.

### [UID:0001MG] `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`

Update the aggregate as contextual/non-emitting:

- keep aggregate C++ blank because it mixes multiple classes, helpers, and padding;
- revise [UID:0001MI] row/notes to say the exact constructor child now carries formal first-draft C++;
- preserve `0x005b52f0-0x005b538a` as the live vtable-routed submit method needing a separate exact child before submit-method C++;
- remove any `95/95` emission-gate wording that claims the constructor cannot emit for that reason.

### [UID:00005U] `by-class/GiveInputPane.md`

Update creator/dispatcher notes:

- retain that the gold branch inline-constructs `GiveGoldInputPane` using prompt id `0x2b`, allocation `0x108` / 264 bytes (Verified with `int_convert.py`), `NumberInputPane`, and the three `GiveGoldInputPane` vtables;
- add that [UID:0001MI] now emits formal constructor C++ through `GiveGoldInputPane`;
- do not move ownership from [UID:00005T] to [UID:00005U];
- replace class-level "final C++ gate 95/95" wording with a current caveat: this class page remains blank pending method/declaration work, but [UID:0001MI] itself is no longer blocked.

### [UID:0001XU] `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`

Update reconstruction notes:

- preserve the warning that raw constructor starts should not be used as IDA function-boundary or direct-call anchors;
- revise the GiveGold sentence so B005 supersedes B015's no-code policy for [UID:0001MI];
- state that [UID:0001MI] is formal first-draft constructor C++ ready while no-route remains an IDA/callgraph caveat;
- keep `0x00630090 -> 0x005b52f0` as the live submit/action slot.

### Check-Only Support

Check the following during implementation and edit only if a direct contradiction is found:

- [UID:0003MW] `by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md`: already sufficient; no routine edit expected.
- [UID:00009L] `by-class/NumberInputPane.md`: already records [UID:0001MI] as a consumer of `NumberInputPane`; no routine edit expected unless old `95/95` language is read as blocking this target.
- [UID:000361] `by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md`: already sufficient as base constructor support.
- [UID:0000RC] `by-global/g_pLanguageMan.md`: already sufficient as singleton/localized-string support; add a GiveGold prompt consumer only if supervisor wants support fanout expansion.
- [UID:0001MH] `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md`: sibling still carries stale `95+` no-code wording, but it is a separate target. Do not modify it in a [UID:0001MI] callback unless the supervisor explicitly expands scope.

## Supervisor-Owned Coverage Text

B005 must not edit `by-memory/-coverage-report.md` during report-only or implementation callback unless explicitly instructed. The current manual row for [UID:0001MI] is stale and likely drives stale generated `74/84` empty-marker output. If the supervisor chooses to correct it before or during implementation, replace the existing row at `by-memory/-coverage-report.md` line 2959 with:

```text
    - [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) 0x005b52b0-0x005b52f0 | raw constructor | GiveGoldInputPaneRawConstructor : reconstructable : 88% : very strong : Source-ready retained GiveGoldInputPane constructor; B005 current MCP session `80de0a67` confirms exact `0x40` / 64-byte constructor-shaped body, prompt id `0x2b` / 43 through `g_pLanguageMan->GetLocalizedString`, `NumberInputPane` base constructor call `0x004f27a0`, primary/secondary/tertiary vtable stores `0x00630048/0x00630098/0x006300c8` at `this+0/+0xa0/+0xa4`, preceding `0x005b52ac-0x005b52b0` padding, matching live inline construction in [UID:00005U][GiveInputPane](by-class/GiveInputPane.md), zero current raw-start xrefs and pointer hits, formal first-draft constructor C++ readiness, and no-route/prompt-spelling evidence retained as confidence caps rather than blank-C++ blockers.
```

If a normal validator run after implementation reverts [UID:0001MI] to stale `74/84` or stale `95+`/blank-C++ wording, the implementation agent should stop and report `PAUSED_VALIDATOR_METADATA_CONFLICT` with command/header proof rather than repeatedly editing through validator-generated defaults.

## Validators Expected After Implementation

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file, for example:

> Executable block R001 was removed from this report and preserved verbatim in [0001MI-GiveGoldInputPaneRawConstructor-source-quality-removed.md](0001MI-GiveGoldInputPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After the target validator, re-read the target header and `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`. The generated file should no longer show [UID:0001MI] as an empty emitter marker if the source page and supervisor-owned manual/default rows are synchronized.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B005/research/0001MI-GiveGoldInputPaneRawConstructor-source-quality.md`

Modified:

- none outside this report.

Report execution: not run. Supervisor validation is required before implementation.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update:
  - [x] [UID:0001MI] `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`
  - [x] [UID:00005T] `by-class/GiveGoldInputPane.md`
  - [x] [UID:0000KC] `by-file/ItemActionInputPanes.md`
  - [x] [UID:0001MG] `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`
  - [x] [UID:00005U] `by-class/GiveInputPane.md`
  - [x] [UID:0001XU] `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`
- [x] Check-only support docs:
  - [x] [UID:0003MW] `by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md`
  - [x] [UID:00009L] `by-class/NumberInputPane.md`
  - [x] [UID:000361] `by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md`
  - [x] [UID:0000RC] `by-global/g_pLanguageMan.md`
  - [x] [UID:0001MH] `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md` only as a sibling-stale note; no edit unless supervisor expands scope.
- [x] Current target state recorded: `86/89`, owner/emitter [UID:00005T], reconstructable true, blank C++, stale `95+ gate` summary.
- [x] Actual evidence checked recorded: current MCP session `80de0a67`, `lookup_funcs`, `insn_query`, `get_bytes`, `xrefs_to`, `find_bytes`, `find`, `get_int`, `callees`, `decompile`, current docs, generated stale rows, and `int_convert.py`.
- [x] Metadata/score changes to apply: [UID:0001MI] to `COMPLETION:88`, `CONFIDENCE:90`; preserve owner/emitter/reconstructable fields.
- [x] Owner/emitter/reconstructable changes to apply: none; preserve [UID:00005T] owner/emitter and reconstructable true.
- [x] Split/rename/new-child changes to apply: none for [UID:0001MI]. Future submit child `0x005b52f0-0x005b538a` remains out of this callback unless separately assigned.
- [x] Source-placement/range/reclassification changes to apply: classify [UID:0001MI] as retained raw constructor-shaped class body with formal first-draft constructor C++; not an IDA function object and not a direct-call anchor.
- [x] First-draft C++ to apply exactly:

```cpp
GiveGoldInputPane::GiveGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetLocalizedString(0x2b))
{
}
```

- [x] Exact target facts to incorporate:
  - [x] prompt id `0x2b` / 43 (Verified with `int_convert.py`);
  - [x] `0x40` / 64-byte exact body (Verified with `int_convert.py`);
  - [x] `0x005b52ac-0x005b52b0` four-byte `0xcc` pre-padding;
  - [x] no modeled function at `0x005b52b0` or `0x005b52ef`;
  - [x] `0x005b52f0` modeled submit function size `0x9a` / 154 (Verified with `int_convert.py`);
  - [x] `g_pLanguageMan` load and `LanguageMan::GetLocalizedString`;
  - [x] `NumberInputPane::NumberInputPane(const wchar_t *)` base construction;
  - [x] vptr stores `0x00630048`, `0x00630098`, `0x006300c8` at `+0`, `+0xa0`, `+0xa4`;
  - [x] live [UID:00005U] inline mirror allocating `0x108` / 264 bytes (Verified with `int_convert.py`) and writing the same vtables;
  - [x] `xrefs_to 0x005b52b0` zero and `find_bytes b0 52 5b 00` zero;
  - [x] `0x00630090 -> 0x005b52f0` active submit route.
- [x] Exact support-doc facts to incorporate:
  - [x] [UID:00005T] class page distinguishes constructor first-draft readiness from still-uncreated submit child.
  - [x] [UID:0000KC] file page aligns [UID:0001MI] with accepted [UID:0001M0]/[UID:0001M5] raw-constructor first-draft policy.
  - [x] [UID:0001MG] aggregate remains contextual/blank C++ but points [UID:0001MI] to formal child C++.
  - [x] [UID:00005U] creator page keeps inline construction evidence without taking ownership.
  - [x] [UID:0001XU] vtable page preserves no-direct-call caveat while superseding B015 no-code policy for [UID:0001MI].
- [x] Historical/stale assumptions and rejected alternatives to preserve:
  - [x] B015 no-route/no-function/no-pointer evidence remains valid audit evidence.
  - [x] B015 "keep formal C++ blank" direction is superseded.
  - [x] old `95+` C++ gate is superseded by the current combined-score/emitter gate.
  - [x] `kGiveGoldPromptStringId` / `LANG_PROMPT_GIVE_GOLD_AMOUNT` remain descriptive/inferred, not formal recovered enum names.
  - [x] reject `GiveInputPane`, `NumberInputPane`, `LanguageMan`, Socket, PacketBuffer, and UserPane as direct owners.
- [x] Wave2/Wave3 mentions or artifacts encountered: no authoritative Wave2/Wave3 evidence used; `simroot_v2`/generated files treated only as stale/generated leads.
- [x] Open questions to document:
  - [x] no raw-start route remains; confidence cap only.
  - [x] exact localized-string enum/source constant spelling unrecovered; use literal `0x2b` in formal C++.
  - [x] submit method still lacks exact child; out of this constructor target.
- [x] Validators to run after implementation: scoped file validators listed above; target should use `--wait-generated`.
- [x] Generated/manual coverage refresh expectation:
  - [x] generated `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` should contain [UID:0001MI] formal constructor code after target validation if source/manual defaults are synchronized.
  - [x] supervisor-owned manual `by-memory/-coverage-report.md` row should be replaced with the exact text in this report; B005 must not edit it unless explicitly authorized.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details currently durable at report-level detail after the narrow [UID:0001MI] target summary correction and uid-only/no-generated validation `000000001169`.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded with command, command_id, timestamp, exit code, ok count, and generated-refresh state.
- [x] Generated output/header checked for [UID:0001MI] constructor code or metadata conflict reported.
- [x] Remaining unapplied accepted items listed with exact blocker.

## Implementation Callback Completion Proof

- Supervisor accepted this report for implementation and later reported resolving the durable metadata conflict. B005 observed the stale summary conflict after target validator `000000000997` and support generated refreshes; supervisor then fixed the source of the stale loop by replacing the manual `by-memory/-coverage-report.md` [UID:0001MI] row and restoring the target summary. After the summary re-staled, B005 performed the supervisor-requested narrow source-header correction and uid-only/no-generated validation `000000001169`.
- Target [UID:0001MI] `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md` now carries `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00005T`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005T`, blank `EMITTER_POSITION_OPTIONAL`, the accepted source-ready `Item Summary`, and the formal constructor code:

```cpp
GiveGoldInputPane::GiveGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetLocalizedString(0x2b))
{
}
```

- Target validator proof:
  - B005 initial target validator: `python .\tools\validator.py --mode file --file by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md --apply --queue-timeout 240 --wait-generated`; `command_id:000000000997`, timestamp `2026-06-25T03:32:29-04:00`, exit `0`, `ok:1`; generated refresh completed and produced `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` with [UID:0001MI] constructor code, but also exposed the stale-summary conflict.
  - Supervisor conflict-resolution target validator: `python .\tools\validator.py --mode file --file by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md --apply --queue-timeout 240 --no-generated-refresh`; `command_id:000000001018`, timestamp `2026-06-25T03:41:58-04:00`, exit `0`, `ok:1`; generated refresh skipped by design.
  - Supervisor manual coverage validator: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240 --no-generated-refresh`; `command_id:000000001019`, timestamp `2026-06-25T03:41:58-04:00`, exit `0`, `ok:1`; known unrelated missing-target warnings; B005 did not edit `by-memory/-coverage-report.md`.
  - Supervisor final source-file-only target validator: `python .\tools\validator.py --mode file --file by-memory\0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md --apply --queue-timeout 240 --no-generated-refresh`; `command_id:000000001082`, timestamp `2026-06-25T03:50:27-04:00`, exit `0`, `ok:1`; generated refresh skipped by design; known unrelated `missing_ref_uid 0003FO` remained.
  - B005 narrow correction target validator: `python .\tools\validator.py --mode file --file by-memory\0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md --uid-only --apply --no-generated-refresh --queue-timeout 240`; `command_id:000000001169`, timestamp `2026-06-25T04:00:03-04:00`, exit `0`, `ok:1`; generated refresh skipped by design; validator reported `insert_header_blank:1`, `projected_stats_update:1`, `stats_incremental_noop:1`, and no reference phase.
- Support validators run by B005 from `source-3/project-documentation`:
  - `python .\tools\validator.py --mode file --file by-class/GiveGoldInputPane.md --apply --queue-timeout 240`; `command_id:000000001005`, timestamp `2026-06-25T03:36:22-04:00`, exit `0`, `ok:1`, generated refresh deferred; known missing UID diagnostics for existing support references.
  - `python .\tools\validator.py --mode file --file by-file/ItemActionInputPanes.md --apply --queue-timeout 240`; `command_id:000000001006`, timestamp `2026-06-25T03:36:30-04:00`, exit `0`, `ok:1`, generated refresh deferred; known missing UID diagnostics for existing child references.
  - `python .\tools\validator.py --mode file --file by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md --apply --queue-timeout 240`; `command_id:000000001007`, timestamp `2026-06-25T03:36:38-04:00`, exit `0`, `ok:1`, generated refresh deferred; known missing UID diagnostics for existing child references.
  - `python .\tools\validator.py --mode file --file by-class/GiveInputPane.md --apply --queue-timeout 240`; `command_id:000000001008`, timestamp `2026-06-25T03:36:46-04:00`, exit `0`, `ok:1`, generated refresh deferred; known missing UID diagnostics for existing support references.
  - `python .\tools\validator.py --mode file --file by-type/by-vtable/ItemActionInputPaneVtableFamily.md --apply --queue-timeout 240`; `command_id:000000001009`, timestamp `2026-06-25T03:36:58-04:00`, exit `0`, `ok:1`, generated refresh deferred.
- Generated output proof: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` header later showed `validator-command-id:000000001159`, `validator-refreshed-at:2026-06-25T03:57:21-04:00`, and still contains [UID:0001MI] `GiveGoldInputPane::GiveGoldInputPane()` with `g_pLanguageMan->GetLocalizedString(0x2b)`. B005 validation `000000001169` intentionally used `--no-generated-refresh`, so no newer generated header is expected from that command.
- Resolved metadata conflict proof from the final B005 correction:
  - Before the correction, the target header still read stale text: `Raw numeric-prompt constructor bytes with prompt id `43`, NumberInputPane base construction, vtable stores, inline construction xrefs from GiveInputPane, and no direct start xref documented; C++ blank under the 95+ gate.`
  - B005 leased only `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`, replaced only the `Item Summary`, validated with uid-only/no-generated command `000000001169`, and re-read the header after validation.
  - Final header readback confirms line 16 now reads: `Source-ready retained GiveGoldInputPane constructor; current MCP session 80de0a67 confirms exact 0x40 bytes, prompt id 0x2b through g_pLanguageMan->GetLocalizedString, NumberInputPane base construction, compiler vptr stores at +0/+0xa0/+0xa4, matching live GiveInputPane inline construction, and no raw-start xrefs or pointer hits; formal first-draft constructor C++ is present while no-route and prompt-id spelling remain confidence caps.`
  - Supervisor-owned manual `by-memory/-coverage-report.md` line 2962 remains the accepted [UID:0001MI] `88% : very strong` row with source-ready constructor wording, validated by supervisor command `000000001019`; B005 did not edit it.
- Support docs updated:
  - [UID:00005T] `by-class/GiveGoldInputPane.md` distinguishes the constructor child as first-draft source-ready while keeping class-page and submit/helper C++ separate.
  - [UID:0000KC] `by-file/ItemActionInputPanes.md` aligns [UID:0001MI] with accepted [UID:0001M0]/[UID:0001M5] retained raw-constructor first-draft policy.
  - [UID:0001MG] `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md` remains aggregate blank-C++ and delegates [UID:0001MI] constructor source to the exact child.
  - [UID:00005U] `by-class/GiveInputPane.md` keeps the live inline construction evidence and explicitly does not take ownership.
  - [UID:0001XU] `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` preserves the no-direct-call/no-IDA-function anchor caveat while superseding B015's no-code policy for [UID:0001MI].
- Check-only support docs were read and left unchanged because they contain no direct contradiction:
  - [UID:0003MW] `by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md` remains a separate no-route packet helper.
  - [UID:00009L] `by-class/NumberInputPane.md` remains base-constructor support only.
  - [UID:000361] `by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md` remains sufficient base-constructor evidence.
  - [UID:0000RC] `by-global/g_pLanguageMan.md` remains sufficient singleton/localized-string support.
  - [UID:0001MH] `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md` is a separate sibling target and was not edited.
- Leases:
  - B005 leased the six initial edit/validator docs and released them; first cleanup after the paused conflict found no active B005 leases.
  - B005 then leased the five support docs for validators `000000001005` through `000000001009` and released all five successfully.
  - B005 finally leased only `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md` to restore the accepted summary after observing it stale again, then released it successfully.
  - B005 correction batch leased only `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`, ran validator `000000001169`, re-read the header, and released the lease immediately.
  - Final lease report read after release showed no active B005 entries.
- Remaining blockers: none for the accepted B005 implementation. The live submit method `0x005b52f0-0x005b538a` still needs a separate exact child before submit-method C++; that is outside this callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001MI-GiveGoldInputPaneRawConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001MI-GiveGoldInputPaneRawConstructor-source-quality.md","timestamp":"2026-06-25T04:11:40","uid":"0001MI"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MI-GiveGoldInputPaneRawConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0001MI-GiveGoldInputPaneRawConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
