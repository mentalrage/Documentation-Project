** TARGET-REPORT-UID:000023 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Source-Quality Report: [UID:000023] ClanAppearNameInputDialog

Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\ClanAppearNameInputDialog.md`

Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\000023-ClanAppearNameInputDialog-source-quality.md`

Assignment: B-only source-quality / heuristic-inference refresh for [UID:000023]. Report-only; no `by-*` documentation files, generated files, shared coverage reports, or `by-memory/-coverage-report.md` were edited.

## Final Recommendation

- Recommended target metadata: raise [UID:000023] from `84/88` to `86/90`.
- Keep `CANONICAL_OWNER:0000I8`, `EMITTER_UIDS:0000I8`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_POSITION_OPTIONAL`.
- Keep the direct source route as [UID:0000I8][Clan](../../../../../by-file/Clan.md), generated under `NexusTK/social/Clan.cpp`.
- Do not move this class alone to [UID:0000IA][ClanDialogs](../../../../../by-file/ClanDialogs.md). `ClanDialogs` remains a future coordinated split candidate for the modal-dialog island, not the active owner.
- Populate class-level C++ with a declaration-only shell and an explicit `[[CHILDREN]]` insertion point placed after the class declaration. This is important because the submitter child already emits a full out-of-class `ClanAppearNameInputDialog::OnSubmitText` method definition.
- Keep the raw constructor child [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](../../../../../by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md) no-code. It is real source-shaped constructor evidence, but the exact raw entry still has no proven inbound route and active construction paths inline the same sequence.
- Keep the submitter child [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](../../../../../by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) as the behavior-body emitter. It already emits the first-draft `OnSubmitText(const wchar_t *)` body.

## Current State Revalidated

Current target:

- [UID:000023][ClanAppearNameInputDialog](../../../../../by-class/ClanAppearNameInputDialog.md): `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I8`, blank formal C++.
- Current prose says class-level C++ remains blank because the raw constructor/class declaration is not final, while exact child [UID:0002O0] now emits `OnSubmitText(const wchar_t *)`.
- Current generated state in `auto-generated/-ag-class-coverage.md`: [UID:000023] is routed/emits to `auto-generated/NexusTK/social/Clan.cpp` but is `code no`.
- Current generated `auto-generated/NexusTK/social/Clan.cpp` contains [UID:0002O0] `ClanAppearNameInputDialog::OnSubmitText` and later empty markers for [UID:000023] and [UID:0002NZ]. This is consistent with the validator's recursive assembly: because [UID:000023] currently has blank code, its coded child bubbles up as child text and empty markers are moved to the generated file's end.

Current children:

- [UID:0002NZ] raw constructor: `85/90`, owner/emitter [UID:000023], blank C++. It documents the retained constructor-shaped range `0x004893a0-0x004893d5`, postpad `0x004893d5-0x004893e0`, no modeled function at the raw start/end, no xrefs, and active inline vtable-store sites.
- [UID:0002O0] submitter: `86/91`, owner/emitter [UID:000023], formal C++ populated. It documents vtable slot `0x00615c74 -> 0x004893e0`, exclusive range `0x004893e0-0x004894ce`, opcode `0x4b`, subtype `9`, action `1`, CP_ACP conversion, one-byte length, payload copy, range guards, and `g_packetSender->QueueAndSendPacket`.

## Evidence Re-read / Rechecked

- Re-read current target class page [UID:000023][ClanAppearNameInputDialog](../../../../../by-class/ClanAppearNameInputDialog.md).
- Re-read exact constructor child [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](../../../../../by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md).
- Re-read exact submitter child [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](../../../../../by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md).
- Re-read base/shared pages: [UID:00002J][ClanNameInputDialog](../../../../../by-class/ClanNameInputDialog.md), [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](../../../../../by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md), [UID:0001TY][ClanInputDialogLayouts](../../../../../by-type/by-struct/ClanInputDialogLayouts.md), [UID:0003HE][ClanModalDialogVtables](../../../../../by-type/by-vtable/ClanModalDialogVtables.md), [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](../../../../../by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md), and [UID:0001X9][ClanDialogVtableFamily](../../../../../by-type/by-vtable/ClanDialogVtableFamily.md).
- Re-read source-family docs [UID:0000I8][Clan](../../../../../by-file/Clan.md) and [UID:0000IA][ClanDialogs](../../../../../by-file/ClanDialogs.md).
- Compared sibling pending/executed reports for `ClanDepMoneyInputDialog`, `ClanWidMoneyInputDialog`, `ClanExpelNameInputDialog`, `ClanSummonNameInputDialog`, and `ClanChangeNameInputDialog`.
- Checked `by-structure.md`, `by-class/-guidance.md`, `inference_research.md`, current generated coverage reports, current generated `Clan.cpp`, and project stats/unresolved rows relevant to [UID:000023], [UID:0002NZ], and [UID:0002O0].
- Re-read validator assembly behavior in `tools/validator_background.py`: children are keyed by `EMITTER_UIDS`; a parent with blank code emits only child text, a parent with explicit `[[CHILDREN]]` replaces that marker, and a by-class/by-type parent without a marker can fallback-insert children before the final `};`. Therefore this target must use `[[CHILDREN]]` after the class declaration to keep full method definitions outside the class body.
- Rechecked local PE bytes and references against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, file size `2679296`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA MCP was not available in this pass; prior live IDA evidence in the docs remains material, and the local PE scan independently revalidated the raw reachability caveat and vtable-store evidence.

Constants verified with `int_convert.py` or existing support docs: `0x35` / 53, `0x0b` / 11, `0xa0` / 160, `0xa4` / 164, `0x5c` / 92, `0x4b` / 75, `0x09` / 9, `0xee` / 238, `0x100` / 256, and `0x80` / 128.

## Local PE Recheck

Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- `.text`: VA `0x00001000`, virtual size `2143404`, raw offset `0x00000400`, raw size `2143744`

Raw constructor target:

- VA: `0x004893a0`
- File offset: `0x000887a0`
- Body length: `0x35` / 53
- Postpad: `0x004893d5-0x004893e0`, `0x0b` / 11 bytes of `0xcc`

Raw bytes:

```text
55 8b ec 51 56 ff 75 08 8b f1 89 75 fc e8 8e f7
ff ff c7 06 18 5c 61 00 8b c6 c7 86 a0 00 00 00
7c 5c 61 00 c7 86 a4 00 00 00 ac 5c 61 00 5e 8b
e5 5d c2 04 00
```

Postpad bytes:

```text
cc cc cc cc cc cc cc cc cc cc cc
```

Constructor-shaped disassembly:

```asm
004893a0  push ebp
004893a1  mov ebp, esp
004893a3  push ecx
004893a4  push esi
004893a5  push dword ptr [ebp + 8]
004893a8  mov esi, ecx
004893aa  mov dword ptr [ebp - 4], esi
004893ad  call 0x00488b40
004893b2  mov dword ptr [esi], 0x00615c18
004893b8  mov eax, esi
004893ba  mov dword ptr [esi + 0xa0], 0x00615c7c
004893c4  mov dword ptr [esi + 0xa4], 0x00615cac
004893ce  pop esi
004893cf  mov esp, ebp
004893d1  pop ebp
004893d2  ret 4
```

Reachability recheck:

- Little-endian VA pointer search for `0x004893a0` (`a0 93 48 00`): zero hits.
- RVA pointer search for `0x000893a0` (`a0 93 08 00`): zero hits.
- Raw-offset pointer search for `0x000887a0` (`a0 87 08 00`): zero hits.
- Direct `.text` relative target scan to `0x004893a0`: zero hits for `call/jmp rel32`, `jcc rel32`, short jump, short conditional jump, and `jecxz` forms.
- Pointer-value search for adjacent submitter `0x004893e0`: one mapped hit at VA `0x00615c74`, the expected primary vtable submit slot.

Vtable constant hits:

- Primary `0x00615c18`: immediate hits at `0x00485286`, `0x0048833e`, and `0x004893b4`; instruction starts `0x00485284`, `0x0048833c`, and `0x004893b2`.
- Secondary `0x00615c7c`: immediate hits at `0x00485290`, `0x00488348`, and `0x004893c0`; instruction starts `0x0048528a`, `0x00488342`, and `0x004893ba`.
- Tertiary `0x00615cac`: immediate hits at `0x0048529a`, `0x00488352`, and `0x004893ca`; instruction starts `0x00485294`, `0x0048834c`, and `0x004893c4`.

Conclusion: the raw constructor body is not padding and not a random compiler tail. It is a retained constructor-shaped body for this class: base constructor call, derived primary/secondary/tertiary vtable installation, `this` return, and `ret 4`. The exact raw entry still has no inbound evidence, while active opener sites at `0x0048527f` and `0x00488337` inline the equivalent `ClanNameInputDialog` construction plus the same three vtable stores. That justifies class declaration C++ and continued no-code status for the raw constructor body.

## Source-Facing Class Shape

Best first-draft source-facing declaration:

```cpp
class ClanAppearNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanAppearNameInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmitText(const wchar_t *text);
};

[[CHILDREN]]
```

Why this shape is safe:

- The base class is `ClanNameInputDialog`, established by the raw constructor body and active inline construction sites.
- The constructor takes the same single packet pointer forwarded to `ClanNameInputDialog::ClanNameInputDialog`. The inherited base decodes the prompt from `packet[3]` and `packet + 4`.
- No class-specific persistent fields are proven beyond inherited `ClanNameInputDialog` state and vfptr views at offsets `+0`, `+0xa0`, and `+0xa4`.
- The unique source behavior is the primary vtable submit override at slot `+0x5c`, represented by child [UID:0002O0].
- `[[CHILDREN]]` after `};` lets [UID:0002O0]'s full out-of-class method definition emit after the declaration. Placing `[[CHILDREN]]` inside the class body or omitting it risks inserting a full `ClanAppearNameInputDialog::OnSubmitText` definition before `};`, which is not the desired generated shape.

Access qualifier note:

- Binary evidence cannot prove original access specifiers.
- Public constructor plus protected submit hook is the best source-facing convention because the submit method is an internal virtual extension point reached from the base dialog's OK handling.
- If a later family-wide header-style pass proves these virtual hooks were declared public, changing `protected` to `public` is a style-level header adjustment and does not affect owner/emitter/range conclusions.

Constructor-body note:

- The source-equivalent constructor shape is likely:

```cpp
ClanAppearNameInputDialog::ClanAppearNameInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}
```

- Do not emit that body yet from [UID:0002NZ]. The exact raw body has no inbound route, and the active construction paths inline the same semantics. Keeping the constructor as a declaration on the class page is the right first-draft C++ compromise.

## Submitter / Packet / Helper Names

Keep [UID:0002O0]'s current method-body interpretation:

- Source-facing method: `int ClanAppearNameInputDialog::OnSubmitText(const wchar_t *text)`.
- Dispatch route: [UID:00010J] `ClanNameInputDialog::OnButtonClick` obtains text control id `4` and calls the derived submit hook through primary vtable slot `+0x5c`.
- Vtable slot: `0x00615c74 -> 0x004893e0`.
- Range: `0x004893e0-0x004894ce`, size `0xee` / 238.
- Packet prefix: opcode `0x4b` / 75, subtype `0x09` / 9, action `1`.
- Payload: convert submitted UTF-16 text through `WideCharToMultiByte(CP_ACP)`, write one-byte converted length, copy converted bytes after the four-byte prefix, and leave the scratch NUL outside the counted packet length.
- Guards: converted length must stay below `0x100` / 256; final packet length must stay below `0x80` / 128.
- Packet byte helper name: `PacketBufferWriteUInt8` remains the best project-facing name for `0x00575380`.
- Copy helper source form: emit as `memmove`, with lower-level wrapper/source relationship documented by the existing child page.
- Sender/global names: `g_packetSender` at `0x0067a7ec`, type `Socket *`, call target `Socket::QueueAndSendPacket(const void *, short)` at `0x00574bb0`.

Rejected alternatives:

- Do not use `SubmitName` as the source method name just because the IDA display name is `ClanAppearNameInputDialog_SubmitName`. That is a useful local analysis alias. The source-facing family name is `OnSubmitText(const wchar_t *)`.
- Do not use `OnConfirmInput` or `OnConfirmName` if encountered in generated/decompiler output. The base vtable dispatch shape and accepted B001 submitter audit support `OnSubmitText`.
- Do not use `int dialogMode` for the constructor parameter. The base constructor consumes packet bytes, and both raw body and active inline openers forward one stack argument to `ClanNameInputDialog`.
- Do not turn range-check/security-cookie scaffolding into application-level source.
- Do not route packet sending through a clan-specific sender; this is normal `g_packetSender` / `Socket::QueueAndSendPacket` behavior.

## Generated / Raw Name Resolution

| Raw/generated name or issue | Source-facing resolution | Evidence and rejection notes |
| --- | --- | --- |
| Raw constructor start `0x004893a0` / possible old `sub_4893A0` style name | Keep as [UID:0002NZ] `ClanAppearNameInputDialogRawConstructor`; no source body yet. | The body is constructor-shaped, but local PE scan and existing IDA docs show no inbound route to the raw start. Active openers inline equivalent construction. |
| Old adjacent submitter name `sub_4893E0` | Remove from source-facing prose; use it only as historical IDA evidence if necessary. | Current IDA/support docs renamed the modeled function to `ClanAppearNameInputDialog_SubmitName`; source-facing method is still `OnSubmitText`. A stale literal `sub_4893E0` currently appears in [UID:0002NZ] and causes a `project-level/-unresolved.md` row. |
| IDA display name `ClanAppearNameInputDialog_SubmitName` | Treat as descriptive local label, not final C++ method spelling. | Vtable family and accepted B001 audit resolve the source-facing virtual hook as `OnSubmitText(const wchar_t *)`. |
| Generated/decompiler constructor shape with `dialogMode` if encountered | Reject. | The base constructor decodes prompt text from packet bytes; raw and active constructor shapes pass one packet pointer. |
| Generated/decompiler method shape with `OnConfirmInput` if encountered | Reject. | The shared base OK-button dispatch calls a submit-text virtual slot; sibling name/money dialog submitters use the same slot. |
| Raw vtable names | Use class vtable names in comments/docs only. | Vtable data pages document generated-binary data; source C++ should declare the class and method, not hand-authored vtable arrays. |
| `PacketBufferWriteUInt8` | Keep. | Existing support docs and child C++ use this packet-byte helper consistently. |
| `memmove`/copy wrapper | Keep source as `memmove`. | Lower-level wrapper identity is not a class-specific source name and does not block C++ readiness. |
| `g_packetSender` and `Socket::QueueAndSendPacket` | Keep. | Existing global/socket support docs and child C++ establish this routing. |

## Owner / Emitter Routing

Recommended metadata after implementation:

| UID | Page | Completion | Confidence | Canonical owner | Reconstructable | Emitters | C++ disposition |
| --- | --- | ---: | ---: | --- | --- | --- | --- |
| `000023` | `by-class/ClanAppearNameInputDialog.md` | `86` | `90` | `0000I8` | `TRUE` | `0000I8` | Populate declaration shell with `[[CHILDREN]]` after class declaration. |
| `0002NZ` | `by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md` | keep `85` | keep `90` | `000023` | `TRUE` | `000023` | Keep formal C++ blank. Add evidence note and remove stale raw-name wording. |
| `0002O0` | `by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md` | keep `86` | keep `91` | `000023` | `TRUE` | `000023` | Keep current `OnSubmitText` C++ body. Optional cross-note only. |

Do not change `EMITTER_POSITION_OPTIONAL` for any of these pages.

Source placement alternatives rejected:

- No one-off move to `ClanDialogs.cpp`: [UID:0000IA] documents a plausible future split, but it explicitly treats [UID:0000I8] `Clan` as the current stronger owner.
- No standalone `ClanAppearNameInputDialog.cpp`: no source/build evidence isolates this class into its own original file.
- No aggregate `ClanNameDialogSubmitters` emitter: exact child method pages already route through their class pages into `Clan.cpp`.
- No vtable-data ownership: [UID:0003HE] and [UID:0002MN] are generated-binary/support docs, not source owners of method bodies.

## Heuristic / Inference Reanalysis And Validation

| Issue | Current resolution | Evidence checked | Effect on score / owner / emitter / C++ readiness |
| --- | --- | --- | --- |
| Raw constructor reachability | Unresolved but bounded. Keep raw child no-code. | Existing IDA no-function/no-xref evidence; fresh local PE VA/RVA/raw-offset pointer scan; fresh relative target scan; active inline opener vtable-store hits. | Blocks [UID:0002NZ] constructor-body C++; does not block [UID:000023] declaration C++. Keeps target below final-audit score. |
| Class declaration shape | Ready. | Base constructor call to `0x00488b40`, inherited layout docs, no extra fields, primary/secondary/tertiary vtable stores, submit slot child. | Supports raising [UID:000023] to `86/90` and adding declaration-level first-draft C++. |
| Constructor parameter | `const unsigned char *packet`. | Base constructor decodes packet prompt; raw constructor pushes `[ebp+8]`; active openers call same base. | Strong enough for declaration. Exact typedef can be refined later without changing semantics. |
| Submit method name | `OnSubmitText(const wchar_t *text)`. | B001 accepted submitter audit; [UID:00010J] base dispatch; vtable slot `+0x5c`; child C++ already emits this shape. | Fully supports child body and class declaration. |
| Extra fields | None declared for derived class. | Raw constructor only writes vfptrs; submitter uses stack buffers and global sender; layout docs show inherited state. | Prevents speculative field declarations; class shell remains conservative. |
| Helper/protocol names | Keep current packet/helper/global names. | Child [UID:0002O0] docs and support pages for packet byte writes, `g_packetSender`, `Socket::QueueAndSendPacket`, and copy helper. | Names are source-ready for submitter; no class-page blocker. |
| Source owner | Keep [UID:0000I8] `Clan`. | `Clan.md`, generated output route, `ClanDialogs.md` split-candidate caveat, no standalone file evidence. | Owner/emitter unchanged. |
| Vtable pages | Support only. | [UID:0003HE] and [UID:0002MN] document vtable group, RTTI, slots, and store refs. | No ownership transfer. |
| Generated/raw names | Resolve to source-facing class/method names and remove stale raw token where possible. | `project-level/-unresolved.md` flags `sub_4893E0`; support docs already preserve exact addresses. | Improves source quality and clears an avoidable unresolved raw-name row after implementation. |
| First-draft C++ gate | [UID:000023] clears it after recommended scores. | `RECONSTRUCTABLE:TRUE`, nonblank emitter route to valid [UID:0000I8] file root, average score `(86 + 90) / 2 = 88`, and bounded declaration content. | Add class declaration only; do not add raw constructor body. |

## Recommended Target Changes

Apply to `by-class/ClanAppearNameInputDialog.md` in an implementation callback.

Header metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Formal C++ block:

```cpp
class ClanAppearNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanAppearNameInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmitText(const wchar_t *text);
};

[[CHILDREN]]
```

Replacement rebuild-handling text:

```text
Rebuild handling: source-authored clan appearance-name dialog attached to [UID:0000I8][Clan](by-file/Clan.md). The class page is ready for declaration-level C++ only; exact method bodies remain on child pages. [UID:0002O0] emits the `OnSubmitText(const wchar_t *)` method body. [UID:0002NZ] remains a no-code raw constructor child because the standalone raw start has no proven inbound route, while active construction paths inline the equivalent base-constructor/vtable-store sequence. The class `[[CHILDREN]]` marker is intentionally placed after the class declaration so full out-of-class child method definitions emit after the shell.
```

Recommended method table rows:

```text
| `ClanAppearNameInputDialog(const unsigned char *packet)` declaration / raw constructor evidence | [UID:0002NZ] `0x004893a0-0x004893d5` | Retained constructor-shaped body: forwards the packet pointer to `ClanNameInputDialog::ClanNameInputDialog`, writes primary/secondary/tertiary vtables `0x00615c18/0x00615c7c/0x00615cac`, and returns `this`; no direct start xrefs or pointer hits, so no constructor-body C++ yet. |
| `OnSubmitText` / appearance request | [UID:0002O0] `0x004893e0-0x004894ce` | Vtable-backed submit hook at primary slot `+0x5c`; sends opcode `0x4b`, subtype `9`, action `1`, converted-name length, and CP_ACP payload bytes via `g_packetSender->QueueAndSendPacket`. |
```

Evidence note to add:

```text
2026-06-20 B002 local PE recheck of `NexusTK.exe` (`2679296` bytes, MD5 `4247e04e20b65d6414c7238aa8ff5515`) reconfirmed the constructor body bytes, `0x35` / 53-byte body size, `0x0b` / 11-byte postpad, zero VA/RVA/raw-offset pointer hits for `0x004893a0`, no direct `.text` relative branch targets to the raw start, one pointer-value hit for submitter `0x004893e0` at vtable slot `0x00615c74`, and active inline construction sequences at `0x0048527f` and `0x00488337` that call `ClanNameInputDialog` and store the same three `ClanAppearNameInputDialog` vtables. Sizes were verified with `int_convert.py`.
```

Score rationale replacement:

```text
| Completion | 86 | The page now resolves class declaration shape, source owner/emitter route, vtable family, child constructor/submitter split, packet semantics, helper/global names, and raw-constructor no-code policy. |
| Confidence | 90 | Submit behavior, vtable identity, source route, and declaration-level class shape are strongly supported by exact child pages, vtable docs, generated-output routing, and fresh local PE ref scans. Confidence remains below final audit because the raw constructor start is still not a modeled/reached function and exact original access specifier/header placement cannot be proven from binary evidence. |
| Reconstructable | true | The class is source-authored and should emit a declaration shell through `Clan.cpp`; child method bodies remain on exact ranged pages. |
```

## Recommended Support-Doc Changes

These are implementation-callback recommendations. They were not applied in this B002 report pass.

1. `by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md`

Keep metadata unchanged:

```text
COMPLETION:85
CONFIDENCE:90
CANONICAL_OWNER:000023
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000023
RECONSTRUCTION_CPP: blank
```

Replace the stale raw-name sentence that currently contains literal `sub_4893E0` with:

```text
IDA DB improvement: C001 renamed the adjacent modeled submitter from its old autogenerated IDA name to `ClanAppearNameInputDialog_SubmitName` after a dry-run succeeded; `lookup_funcs` verified the new name and `idb_save` wrote `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`. Source-facing docs should still use `ClanAppearNameInputDialog::OnSubmitText(const wchar_t *)`.
```

Add this B002 evidence note:

```text
2026-06-20 B002 local PE recheck (`NexusTK.exe`, `2679296` bytes, MD5 `4247e04e20b65d6414c7238aa8ff5515`) reconfirmed the exact `0x004893a0-0x004893d5` bytes, `0x35` / 53-byte body size, eleven `0xcc` bytes at `0x004893d5-0x004893e0`, zero VA/RVA/raw-offset pointer hits for the raw start, no direct `.text` relative instruction target to `0x004893a0`, and vtable immediate hits for `0x00615c18`, `0x00615c7c`, and `0x00615cac` at active opener sites `0x00485284/0x0048528a/0x00485294`, `0x0048833c/0x00488342/0x0048834c`, plus this raw body. This confirms source-shaped constructor evidence but keeps constructor-body C++ blank until raw reachability policy changes or new inbound evidence appears.
```

2. `by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md`

No metadata or C++ change required. Optional cross-note:

```text
2026-06-20 B002 class-page refresh keeps this method as the behavior-body emitter for [UID:000023]. The parent class page should emit only the declaration shell with `[[CHILDREN]]` after the class declaration so this full out-of-class `ClanAppearNameInputDialog::OnSubmitText` definition assembles after the class shell.
```

3. `by-file/Clan.md`

Recommended replacement for the `ClanAppearNameInputDialog` row:

```text
| `ClanAppearNameInputDialog` | raw constructor [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md); submitter [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) | `social/Clan.cpp` dialog | Class page is declaration-ready with `ClanNameInputDialog` inheritance and `[[CHILDREN]]`; raw constructor child remains no-code because the standalone raw start has no inbound route; exact submitter child emits `OnSubmitText(const wchar_t *)` and sends opcode `0x4b`, subtype `9`, action `1`, converted-name length, and CP_ACP payload bytes. |
```

Recommended short history note:

```text
2026-06-20 B002 refresh for [UID:000023] `ClanAppearNameInputDialog` resolves declaration-level class C++ readiness while preserving the retained/no-route raw constructor caveat. The class stays in `social/Clan.cpp`; [UID:0002O0] remains the emitted behavior body and [UID:0002NZ] remains a no-code constructor-evidence child.
```

4. `by-file/ClanDialogs.md`

Add a narrow source-placement note:

```text
2026-06-20 B002 [UID:000023] refresh keeps `ClanAppearNameInputDialog` owned/emitted through [UID:0000I8][Clan](by-file/Clan.md). This page remains a coordinated future `ClanDialogs.cpp` split candidate for the modal-dialog island, not the active owner for one-off class migration.
```

5. `by-type/by-struct/ClanInputDialogLayouts.md`

Add a layout note:

```text
2026-06-20 B002 refresh for [UID:000023] confirms no derived persistent fields for `ClanAppearNameInputDialog` beyond inherited `ClanNameInputDialog` state and the primary/secondary/tertiary vfptr views at `+0`, `+0xa0`, and `+0xa4`. The derived class's unique behavior is its `OnSubmitText(const wchar_t *)` override at primary slot `+0x5c`.
```

6. `by-type/by-vtable/ClanModalDialogVtables.md` or `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`

Optional cross-reference text:

```text
2026-06-20 B002 [UID:000023] refresh treats `0x00615c74 -> 0x004893e0` as `ClanAppearNameInputDialog::OnSubmitText(const wchar_t *)`; primary/secondary/tertiary vtable bases `0x00615c18/0x00615c7c/0x00615cac` remain generated-binary support for the class declaration, not standalone source emitters.
```

7. `project-level/-unresolved.md`

Do not hand-edit this generated/shared report. After the raw constructor page removes the literal `sub_4893E0`, run the normal validator/documented refresh. The current unresolved row:

```text
### `sub_4893E0`
...
by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md
```

should disappear when the generated unresolved report is next rebuilt.

## Exact Coverage Text

Recommended replacement row for `by-class/-coverage-report.md`:

```text
- [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md) : reconstructable : 86% : very strong : B002 2026-06-20 source-quality refresh confirms this class as a `ClanNameInputDialog`-derived appearance-name submit dialog owned/emitted through [UID:0000I8] `Clan` into `social/Clan.cpp`; fresh PE recheck of constructor evidence `0x004893a0-0x004893d5` confirms the `0x35` / 53-byte base-constructor/vtable-store body, `0x0b` / 11-byte postpad, zero VA/RVA/raw-offset pointer hits, no direct `.text` relative branch targets, one submitter pointer hit at vtable slot `0x00615c74`, and equivalent inline construction at `0x0048527f` and `0x00488337`; vtable data confirms primary/secondary/tertiary bases `0x00615c18/0x00615c7c/0x00615cac`; submitter child [UID:0002O0] already emits `OnSubmitText(const wchar_t *)` for opcode `0x4b`, subtype `9`, action `1`; add declaration-only class C++ with `[[CHILDREN]]` after the class declaration while keeping raw constructor child [UID:0002NZ] C++ blank because standalone constructor reachability remains unproven.
```

No replacement row is required for `by-memory/-coverage-report.md`. Existing rows for [UID:0002NZ] and [UID:0002O0] remain substantively correct. Do not edit `by-memory/-coverage-report.md` in a B002 implementation callback. If the supervisor later wants the fresh PE scan mirrored there, that should be a separate supervisor-owned coverage update.

## Expected Generated Output After Implementation

After the target class page receives declaration C++ and validators/autogen run:

- [UID:000023] should change from `code no` to `code yes` in `auto-generated/-ag-class-coverage.md`.
- [UID:0002O0] should remain `coded` / `yes` in `auto-generated/-ag-memory-coverage.md`.
- [UID:0002NZ] should remain routed/emits but `code no`.
- `auto-generated/NexusTK/social/Clan.cpp` should contain one [UID:000023] snippet with the class declaration, followed by [UID:0002O0]'s full out-of-class `ClanAppearNameInputDialog::OnSubmitText` definition at the `[[CHILDREN]]` insertion point.
- There should be no duplicate [UID:0002O0] method body.
- There should be no literal `[[CHILDREN]]` or `[[No Children Attached]]` left in generated `Clan.cpp`.
- Empty marker comments for blank children may be moved to the generated file's end by the validator; that is normal.

## IDA Rename / Type / Comment Recommendations

These are optional analysis-database recommendations, not documentation edits required for this report.

- Do not force-create a modeled function at `0x004893a0` yet. If adding labels/comments only, use a name such as `ClanAppearNameInputDialog_ctor_raw_no_xref` and comment that the raw entry has no proven inbound route.
- If a provisional type is useful for analysis, use:

```cpp
ClanAppearNameInputDialog *__thiscall ClanAppearNameInputDialog_ctor_raw(
    ClanAppearNameInputDialog *this,
    const unsigned char *packet);
```

- For `0x004893e0`, keep or add source-facing comment/name `ClanAppearNameInputDialog::OnSubmitText(const wchar_t *)`. Existing IDA name `ClanAppearNameInputDialog_SubmitName` is acceptable as a local descriptive alias but should not be the final source name in docs/C++.
- Name/comment vtable bases:
  - `0x00615c18`: `ClanAppearNameInputDialog::vftable` / primary vtable.
  - `0x00615c7c`: `ClanAppearNameInputDialog::secondary_vftable`.
  - `0x00615cac`: `ClanAppearNameInputDialog::tertiary_vftable`.
- Comment `0x00615c74` as submit virtual slot `+0x5c -> ClanAppearNameInputDialog::OnSubmitText`.
- Comment raw constructor sites:
  - `0x004893ad`: `ClanNameInputDialog::ClanNameInputDialog(packet)`.
  - `0x004893b2`, `0x004893ba`, `0x004893c4`: primary/secondary/tertiary `ClanAppearNameInputDialog` vtable stores.
- Comment opener inline sites `0x0048527f` and `0x00488337` as active inline construction sequences for `ClanAppearNameInputDialog`.

## Implementation Checklist

For a later supervisor-approved implementation callback:

1. Open `by-class/ClanAppearNameInputDialog.md`.
2. Change `COMPLETION` to `86` and `CONFIDENCE` to `90`; keep owner/emitter metadata unchanged.
3. Populate the formal C++ block exactly with the declaration shell shown in this report, including `[[CHILDREN]]` after the closing `};`.
4. Replace the target page rebuild-handling prose with the recommended declaration-only / raw-constructor-no-code wording.
5. Replace or add the constructor and submitter rows in the target page's method table.
6. Add the 2026-06-20 B002 local PE evidence note to the target page.
7. Update the target page score rationale to explain why declaration C++ is ready but raw constructor-body C++ is still withheld.
8. Open [UID:0002NZ] raw constructor page.
9. Remove the literal `sub_4893E0` from prose by applying the recommended sentence replacement; this should clear the current unresolved raw-name row after generated unresolved refresh.
10. Add the B002 PE recheck note to [UID:0002NZ], keeping its score, owner/emitter, and blank formal C++ unchanged.
11. Open [UID:0002O0] submitter page only if adding the optional parent-declaration cross-note; do not change its current C++ body or scores.
12. Update the `ClanAppearNameInputDialog` row in [UID:0000I8] `Clan.md` with the exact row in this report.
13. Add the narrow source-placement note to `ClanDialogs.md`; do not change its owner/path role.
14. Add the no-extra-fields / submit-slot note to `ClanInputDialogLayouts.md`.
15. Optionally add the vtable slot cross-reference to `ClanModalDialogVtables.md` or the vtable-data memory page.
16. Update `by-class/-coverage-report.md` with the exact replacement row above.
17. Do not edit `by-memory/-coverage-report.md`.
18. Run the file validators below for every edited by-* target/support doc.
19. Run an autogen refresh or rely on the final file validator's autogen phase, then inspect generated `Clan.cpp` for the expected class shell plus a single child method body.
20. Run a broader documented/rescore refresh only if the supervisor wants `project-level/-unresolved.md` and completion stats regenerated immediately after the stale raw-name removal.

## Validator Commands After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

Minimum file validators for the recommended by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [000023-ClanAppearNameInputDialog-source-quality-removed.md](000023-ClanAppearNameInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional vtable-data memory page is edited instead of or in addition to `ClanModalDialogVtables.md`, run:

> Executable block R002 was removed from this report and preserved verbatim in [000023-ClanAppearNameInputDialog-source-quality-removed.md](000023-ClanAppearNameInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-validator generated-output checks:

> Executable block R003 was removed from this report and preserved verbatim in [000023-ClanAppearNameInputDialog-source-quality-removed.md](000023-ClanAppearNameInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional broader refresh after all implementation edits, if the supervisor wants generated unresolved/stats refreshed immediately:

> Executable block R004 was removed from this report and preserved verbatim in [000023-ClanAppearNameInputDialog-source-quality-removed.md](000023-ClanAppearNameInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run in this report-only pass because no by-* target/support docs were edited.

## Remaining Open Questions

- Exact original access specifier for `OnSubmitText`: not binary-observable. The report recommends `protected`; `public` remains a possible family-style adjustment if later headers prove it.
- Exact original constructor parameter typedef: evidence supports `const unsigned char *packet`; a future `BYTE *` or packet-buffer typedef can replace it if the project standardizes packet types.
- Exact original source split: current evidence supports `Clan.cpp`; `ClanDialogs.cpp` remains plausible only as a coordinated future split.
- Raw constructor entry reachability: still unsolved. Evidence checked: existing IDA no-function/no-xref docs, local PE VA/RVA/raw-offset pointer scans, local `.text` relative target scan, and active inline opener sequences. Result: no safe standalone constructor-body emission from [UID:0002NZ].
- Exact MSVC-decorated vtable names: not needed for source docs. Use class/method declarations and keep vtable bytes in support pages.

## Readiness

Ready for supervisor review and implementation callback. The safe implementation unit is documentation plus declaration-level class C++. Do not move owner/emitter, do not edit `by-memory/-coverage-report.md`, and do not emit the raw constructor body unless new reachability evidence appears or the supervisor explicitly accepts a broader retained-constructor policy.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/000023-ClanAppearNameInputDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"000023"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000023-ClanAppearNameInputDialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/000023-ClanAppearNameInputDialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000023"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
