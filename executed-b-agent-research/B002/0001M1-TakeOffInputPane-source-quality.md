** TARGET-REPORT-UID:0001M1 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: UID 0001M1 - TakeOffInputPane

Assignment: `B002-report-take-off-input-pane-source-quality-0001M1-mcp-20260623`

Target: [UID:0001M1] `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0001M1-TakeOffInputPane-source-quality.md`

Report-only result: no target/support by-* docs, no generated/project-level files, no tool state, no IDA DB state, and no `-coverage-report.md` files were edited.

Implementation callback result: accepted non-coverage details were applied on 2026-06-23. Target/support by-* docs were updated, exact child pages [UID:00041L] and [UID:00041M] were created through validator UID allocation, scoped validators passed, and `by-memory/-coverage-report.md` remains supervisor-owned and unapplied.

## Final Recommendation

Recommendation for [UID:0001M1]:

- Raise target metadata from `86/86` to `87/89`.
- Keep `CANONICAL_OWNER:0000EC`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000EC`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep formal `RECONSTRUCTION_CPP` blank.
- Preserve [UID:0001M2] `SendTakeOffPacket` as the exact file-level helper child with its existing first-draft C++.
- Do not emit aggregate C++ from [UID:0001M1]. The page is a mixed aggregate containing two TakeOff class virtual bodies, a file-level helper child owned by [UID:0000KC], and padding fences. Emitting parent C++ would duplicate child [UID:0001M2] and would force unresolved event/command helper labels into source.
- If implementation scope allows split work, create exact child pages for the two source-bearing class methods:
  - `0x005b2720-0x005b27b3` descriptive role `TakeOffInputPane::HandleTakeOffShortcut` / key-event shortcut slot.
  - `0x005b2830-0x005b296b` descriptive role `TakeOffInputPane::ProcessUnequipCommand` / submit-action slot.
- Keep those new exact method children blank-C++ on first creation unless a separate source-quality pass standardizes the event argument type/fields and the `sub_4F2310` / `sub_4F2300` command-input helper names.

The current page can move above `86/86` because current MCP now verifies the function inventory, vtable slot routes, caller/callee sets, padding fences, raw-constructor sibling state, table/global refs, and the shared-helper split. It should not move into near-final range because exact method child pages do not exist and the source-facing virtual names, event fields, and command-input helper APIs remain descriptive rather than original-source quality.

## Evidence Inputs And Limits

Required project workflow:

- Read `tools/leaser/Agents/Agent-B002/goal.md`.
- Used the project-level `ntk-b-agent-workflow` skill.
- Read `by-structure.md` sections for by-memory scoring, aggregate/container behavior, and current code-entry requirements.
- No subagents were spawned.
- No lease was taken because this was report-only research.

Current IDA MCP evidence:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Session: `ff68e691`.
- Input IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `idb_list` reported session `ff68e691` active, `is_analyzing:false`, `is_active:true`, worker/backend present.
- `server_health(database=ff68e691)` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, module `NexusTK.exe`, imagebase `0x400000`.
- `tools/list` returned 65 MCP tools. Used `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `xrefs_to`, `callees`, `find_bytes`, and `get_global_value`.

Supporting docs read as leads and cross-checks:

- Target [UID:0001M1] `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`.
- Raw constructor sibling [UID:0001M0] `by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md`.
- Helper child [UID:0001M2] `by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md`.
- [UID:0000EC] `by-class/TakeOffInputPane.md`.
- [UID:0000KC] `by-file/ItemActionInputPanes.md`.
- [UID:0001XU] `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`.
- Global/storage docs for `g_equipmentSlotKeys`, `g_activeDialogCount`, and `g_packetSender`.
- Neighboring item-action pages for Wield/Wear aggregate and helper policy.
- Archived B006 [UID:0001M2] report was used as a lead only; this report rechecked the key helper facts with current MCP session `ff68e691`.

Numeric conversions were checked with `tools/int_convert.py --size 4`. Relevant conversions:

- `0x93` = decimal `147`.
- `0x67` = decimal `103`.
- `0x13b` = decimal `315`.
- `0x40` = decimal `64`.
- `0x24b` = decimal `587`.
- `0xd` = decimal `13`.
- `0x9` = decimal `9`.
- `0x5` = decimal `5`.
- `0x2d` = decimal `45`.
- `0x1f` = decimal `31`.
- `0x2` = decimal `2`.
- `0x22` = decimal `34`.
- `0x108` = decimal `264`.
- `0xa0` = decimal `160`.
- `0xa4` = decimal `164`.
- `0x84` = decimal `132`.
- `0x2e` = decimal `46`.
- `0x17` = decimal `23`.
- `0x38` = decimal `56`.
- `0x41` = decimal `65`.
- `0x3f` = decimal `63`.

Important limit:

- Current MCP `get_bytes` / `get_global_value` reports `0x0069b380` as `0x00` in this IDB, while older `g_activeDialogCount` docs record an initial `0xff`. This report does not resolve the global's declaration/init history. The TakeOff behavior still uses signed positive-blocking semantics because the code checks `cmp byte ptr unk_69B380, 0` followed by `jg` at both target gates.

## Target Current State

Current target metadata:

```text
UID:0001M1
COMPLETION:86
CONFIDENCE:86
CANONICAL_OWNER:0000EC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000EC
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Current generated output contains only an empty marker for [UID:0001M1]:

```cpp
// UID:0001M1 | by-memory\0x005b2720-0x005b296b.TakeOffInputPane.md | Completion:86 | Confidence:86 | Empty Emitter Marker
```

The current by-memory coverage ledger row is stale relative to the target header and current MCP facts:

```text
    - [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md) 0x005b2720-0x005b296b | class-method-cluster | TakeOffInputPane : reconstructable : 78% : strong : TakeOff shortcut, packet helper, command handler, `A` all-equipment branch, slot-key table scan, vtable xrefs, and internal padding splits documented.
```

## Current MCP Function And Boundary Inventory

`lookup_funcs(database=ff68e691)` at `2026-06-23T17:31:49Z` returned:

| Query | Result |
| --- | --- |
| `0x004f2010` | `sub_4F2010`, size `0x82` |
| `0x004f2092` | Not a function |
| `0x005b26e0` | Not a function |
| `0x005b2720` | `sub_5B2720`, size `0x93` / 147 |
| `0x005b27b3` | Not a function |
| `0x005b27c0` | `sub_5B27C0`, size `0x67` / 103 |
| `0x005b2827` | Not a function |
| `0x005b2830` | `sub_5B2830`, size `0x13b` / 315 |
| `0x005b296b` | Not a function |
| `0x005b2970` | Not a function |
| `0x005b77c8` | `sub_5B77C8`, size `0xb` |
| `0x005b77d3` | `sub_5B77D3`, size `0xb` |
| `0x005b7940` | `sub_5B7940`, size `0x3b` |
| `0x005b797b` | Not a function |
| `0x005aa0c0` | `sub_5AA0C0`, size `0x80` |
| `0x00568cb0` | `sub_568CB0`, size `0x69a` |

Target-internal half-open split:

| Range | Role | Current MCP evidence |
| --- | --- | --- |
| `0x005b2720-0x005b27b3` | TakeOff key/shortcut virtual method | `sub_5B2720`, size `0x93`; vtable data xref at `0x0062f984`; `find_bytes 20 27 5b 00` matched only `0x0062f984`. |
| `0x005b27b3-0x005b27c0` | Padding | `get_bytes` returned thirteen `0xcc` bytes. |
| `0x005b27c0-0x005b2827` | [UID:0001M2] `SendTakeOffPacket` | `sub_5B27C0`, size `0x67`; 28 direct code callers; `find_bytes c0 27 5b 00` returned zero direct VA data hits. |
| `0x005b2827-0x005b2830` | Padding | `get_bytes` returned nine `0xcc` bytes. |
| `0x005b2830-0x005b296b` | TakeOff submit/command virtual method | `sub_5B2830`, size `0x13b`; vtable data xref at `0x0062f974`; `find_bytes 30 28 5b 00` matched only `0x0062f974`. |
| `0x005b296b-0x005b2970` | Post-target padding | `get_bytes` returned five `0xcc` bytes. This is outside the [UID:0001M1] half-open target but should stay documented in ignored/padding coverage. |

Sibling raw constructor:

- [UID:0001M0] remains exactly `0x005b26e0-0x005b2720`.
- `lookup_funcs 0x005b26e0` returned Not a function.
- `xrefs_to 0x005b26e0` returned zero cross-references.
- `find_bytes e0 26 5b 00` returned zero raw VA pointer hits.
- `decompile 0x005b26e0` failed with `Decompilation failed at 0x5b26e0`.
- `get_bytes 0x005b26e0+0x40` returned the complete 64-byte constructor-shaped body:

```text
55 8b ec 51 56 8b f1 8b 0d 50 a7 67 00 6a 22 89
75 fc e8 59 dc f3 ff 50 8b ce e8 a1 01 f4 ff c7
06 2c f9 62 00 8b c6 c7 86 a0 00 00 00 7c f9 62
00 c7 86 a4 00 00 00 ac f9 62 00 5e 8b e5 5d c3
```

Raw constructor disassembly:

```asm
0x005b26e7  mov ecx, dword_67A750
0x005b26ed  push 22h
0x005b26f2  call sub_4F0350
0x005b26fa  call sub_4F28A0
0x005b26ff  mov dword ptr [esi], offset ??_7TakeOffInputPane@@6B@
0x005b2707  mov dword ptr [esi+0A0h], offset ??_7TakeOffInputPane@@6B@_0
0x005b2711  mov dword ptr [esi+0A4h], offset ??_7TakeOffInputPane@@6B@_1
0x005b271f  retn
```

Current command-factory mirror:

- `decompile 0x005aa0c0` succeeds.
- It allocates `0x108` / 264 bytes with `sub_4F4AA0(264)`.
- It requests localized prompt id `0x22` / 34 through `sub_4F0350(dword_67A750, 34)`.
- It calls `sub_4F28A0`.
- It stores the same three TakeOffInputPane vtable views at `0x005aa116`, `0x005aa11c`, and `0x005aa126`.
- This is strong constructor-shape evidence but it is not a direct call/xref route to raw start `0x005b26e0`.

## Current MCP Xrefs, Vtables, And Pointer Routes

`xrefs_to(database=ff68e691)` at `2026-06-23T17:31:49Z` returned:

| Address | Count | Evidence |
| --- | ---: | --- |
| `0x005b26e0` | 0 | No cross-references to raw constructor start. |
| `0x005b2720` | 1 | Data xref from `0x0062f984`. |
| `0x005b27c0` | 28 | 14 calls from `sub_568CB0` / SelfLookPane path and 14 calls from `sub_5B2830` / TakeOff uppercase `A` path. |
| `0x005b2830` | 1 | Data xref from `0x0062f974`. |
| `0x0062f92c` | 3 | Stores from `0x005a6ca4`, `0x005aa116`, raw constructor `0x005b26ff`. |
| `0x0062f97c` | 3 | Stores from `0x005a6cac`, `0x005aa11c`, raw constructor `0x005b2707`. |
| `0x0062f9ac` | 3 | Stores from `0x005a6cb6`, `0x005aa126`, raw constructor `0x005b2711`. |
| `0x00630bd8` | 1 | Data xref at `0x005b28f0` inside `sub_5B2830`. |
| `0x0069b380` | 13 | Dialog mutators and inventory/spell/take-off consumers; TakeOff refs at `0x005b27d3` and `0x005b2914`. |
| `0x0067a7ec` | 489 | High-fanout packet sender global. Current `xrefs_to` with limit 1000 returned all 489 refs and `more:false`. |

Direct VA/pointer pattern scan:

| Pattern | Meaning | Matches |
| --- | --- | --- |
| `e0 26 5b 00` | VA `0x005b26e0` | 0 |
| `20 27 5b 00` | VA `0x005b2720` | `0x0062f984` only |
| `c0 27 5b 00` | VA `0x005b27c0` | 0 |
| `30 28 5b 00` | VA `0x005b2830` | `0x0062f974` only |
| `2c f9 62 00` | vtable base `0x0062f92c` | `0x005a6ca6`, `0x005aa118`, `0x005b2701` |
| `7c f9 62 00` | vtable base `0x0062f97c` | `0x005a6cb2`, `0x005aa122`, `0x005b270d` |
| `ac f9 62 00` | vtable base `0x0062f9ac` | `0x005a6cbc`, `0x005aa12c`, `0x005b2717` |
| `d8 0b 63 00` | `g_equipmentSlotKeys` VA | `0x005b28f4` only |
| `80 b3 69 00` | `g_activeDialogCount` VA | 13 matches, mirroring direct xrefs |
| `ec a7 67 00` | `g_packetSender` VA | 489 matches |

Vtable slot bytes:

```text
0x0062f974: 30 28 5b 00 a8 2b 65 00 c8 77 5b 00 f0 24 4f 00
0x0062f984: 20 27 5b 00 80 25 4f 00 60 27 4f 00 f0 4d 54 00
```

Interpretation:

- Primary vtable slot `0x0062f974` points to `0x005b2830`, matching the TakeOff submit/action method slot.
- Secondary vtable slot `0x0062f984` points to `0x005b2720`, matching the TakeOff key-event/shortcut slot.
- `0x005b27c0` is not vtable-backed. It is a normal free helper reached by direct `call` instructions only.

## Current MCP Decompilation And Behavior

### `0x005b2720-0x005b27b3` key/shortcut method

`decompile 0x005b2720` returned:

```c
char __thiscall sub_5B2720(_DWORD *this, _BYTE *a2)
{
  _BYTE Src[16];

  if ( (unsigned __int8)std::ctype<char>::do_narrow(a2[8], (unsigned __int8)a2[266]) != 63 || a2[266] != 4 || a2[4] != 8 )
    return sub_4F2920(this, (int)a2);
  sub_575380(45, Src);
  Src[1] = 0;
  sub_574BB0((_BYTE *)dword_67A7EC, Src, 1);
  return 1;
}
```

Disassembly details:

- Reads `dword_67A754` as the ctype/event support object before calling `std::ctype<char>::do_narrow`.
- Tests narrowed character `0x3f` / `?`.
- Tests event byte `a2[0x10a] == 4`.
- Tests event byte `a2[4] == 8`.
- Fallback calls `sub_4F2920(this, event)`, the base `CharInputPane` style input handler.
- On shortcut match, writes packet opcode `0x2d` / 45, writes a local terminator byte, and calls `sub_574BB0(dword_67A7EC, packet, 1)`.
- Returns `1` on handled shortcut; returns base-handler result otherwise.

Source-quality interpretation:

- `HandleTakeOffShortcut` is a good descriptive role name, but the original virtual name is still inferred from vtable slot position and sibling patterns.
- The event argument type and field names for offsets `+0x04`, `+0x08`, and `+0x10a` are not standardized enough for source-quality C++.
- This exact method should not emit formal C++ until the project has source-facing names for the shared key/input event structure and base virtual.

### `0x005b27c0-0x005b2827` shared helper [UID:0001M2]

`decompile 0x005b27c0` returned:

```c
int __cdecl sub_5B27C0(char a1)
{
  int result;
  char Src;
  _BYTE v3[127];

  if ( unk_69B380 <= 0 )
  {
    sub_575380(31, &Src);
    sub_575380(a1, v3);
    v3[1] = 0;
    return sub_574BB0((_BYTE *)dword_67A7EC, &Src, 2);
  }
  return result;
}
```

Disassembly details:

- Stack frame reserves `0x84` / 132 bytes: 128-byte packet scratch buffer plus the cookie local.
- `cmp byte ptr unk_69B380, 0` / `jg` skips the send only when the dialog gate is positive.
- Writes opcode `0x1f` / 31.
- Uses `movsx` from byte argument, supporting `char equipmentSlotSelector`.
- Writes selector as byte 1.
- Clears a local scratch terminator at packet byte 2.
- Calls `sub_574BB0(dword_67A7EC, packet, 2)`.

Current generated output already contains the accepted B006 first-draft C++:

```cpp
void SendTakeOffPacket(char equipmentSlotSelector)
{
    char packet[128];

    if (g_activeDialogCount <= 0) {
        PacketBufferWriteUInt8(0x1f, packet);
        PacketBufferWriteUInt8(equipmentSlotSelector, packet + 1);
        packet[2] = 0;
        g_packetSender->QueueAndSendPacket(packet, 2);
    }
}
```

Current MCP supersedes the archived B006 local-export limitation. [UID:0001M2] can retain `89/90`, owner/emitter [UID:0000KC], and first-draft C++.

### `0x005b2830-0x005b296b` submit/command method

`decompile 0x005b2830` returned:

```c
__int16 __thiscall sub_5B2830(_DWORD **this)
{
  __int16 result;
  char v3;
  int v4;
  int v5;
  char Src;
  _BYTE v7[127];

  result = sub_4F2310(this);
  if ( result == 1 )
  {
    sub_4F2300(this, &v5, 1);
    result = v5;
    if ( (_WORD)v5 == 65 )
    {
      sub_5B27C0(1);
      sub_5B27C0(2);
      sub_5B27C0(3);
      sub_5B27C0(4);
      sub_5B27C0(6);
      sub_5B27C0(7);
      sub_5B27C0(8);
      sub_5B27C0(13);
      sub_5B27C0(14);
      sub_5B27C0(16);
      sub_5B27C0(20);
      sub_5B27C0(21);
      sub_5B27C0(22);
      return sub_5B27C0(23);
    }
    else
    {
      v3 = 0;
      v4 = 0;
      while ( (_WORD)v5 != word_630BD8[v4] )
      {
        v4 = ++v3;
        if ( v3 >= 23 )
          return result;
      }
      if ( unk_69B380 <= 0 )
      {
        sub_575380(31, &Src);
        sub_575380(v3 + 1, v7);
        v7[1] = 0;
        return sub_574BB0((_BYTE *)dword_67A7EC, &Src, 2);
      }
    }
  }
  return result;
}
```

Disassembly details:

- Calls `sub_4F2310(this)` and proceeds only when it returns `1`.
- Calls `sub_4F2300(this, &wideChar, 1)` to fetch one character.
- Compares the input wchar to `0x0041` / decimal `65` / uppercase `A`.
- Uppercase `A` branch calls [UID:0001M2] for exactly these selectors:

```text
1, 2, 3, 4, 6, 7, 8, 13, 14, 16, 20, 21, 22, 23
```

- Non-`A` branch scans `g_equipmentSlotKeys` at `0x00630bd8` for up to `0x17` / 23 entries.
- On table match, computes selector `index + 1`, checks `g_activeDialogCount <= 0`, then writes opcode `0x1f`, writes the selector, clears the local-only byte after the selector, and calls `g_packetSender` / `QueueAndSendPacket` with length `2`.
- Therefore, the typed single-slot TakeOff path does not call [UID:0001M2]; it emits the same two-byte packet inline.

Source-quality interpretation:

- `ProcessUnequipCommand` or `OnSubmitInput` is a good descriptive role. The vtable slot `0x0062f974` and sibling item-action patterns support a submit/action virtual.
- Exact original method name and return convention remain unresolved. The decompiler's `__int16` return reflects the base command helper flow; source could be `bool`, `short`, or inherited virtual return type.
- `sub_4F2310` and `sub_4F2300` are not yet project-wide source-named enough for formal C++ on this method.
- This exact method should be split into its own page before any draft C++ is attempted.

## Globals And Data Rechecked

### `g_equipmentSlotKeys`

Current MCP facts:

- `get_bytes 0x00630bd8+0x2e` returned 23 UTF-16 words:

```text
77 00 61 00 73 00 68 00 23 00 6e 00 6c 00 72 00
23 00 23 00 23 00 23 00 66 00 6d 00 23 00 63 00
23 00 23 00 23 00 5b 00 5d 00 31 00 32 00
```

- Decoded contents: `wash#nlr####fm#c###[]12`.
- `xrefs_to 0x00630bd8` returned one data xref at `0x005b28f0` inside `sub_5B2830`.
- `find_bytes d8 0b 63 00` returned `0x005b28f4` only.

Interpretation:

- This is a fixed 23-entry table, not a string.
- Placeholder `#` entries preserve one-based selector numbering.
- Valid selector IDs are the same set used by the uppercase `A` branch and by [UID:0001M2] callers.
- [UID:0001M2] shares the selector domain by argument constants but does not read this table directly.

### `g_activeDialogCount`

Current MCP facts:

- `xrefs_to 0x0069b380` returned 13 direct refs, including TakeOff refs at `0x005b27d3` and `0x005b2914`.
- `find_bytes 80 b3 69 00` also returned 13 matches.
- `get_bytes 0x0069b380+1` returned `0x00`.
- `get_global_value 0x0069b380` and `get_global_value byte_69B380` both returned `0x0`.

Interpretation:

- For this target, the behavioral expression remains `g_activeDialogCount <= 0` because the code uses signed `jg` to skip sends when the byte is positive.
- Existing global docs that discuss an older `0xff` byte should be treated as a support-doc reconciliation item. This target report should not silently repeat `0xff` as current-session evidence.
- ItemActionInputPanes and TakeOff are consumers only. DialogPane remains the storage owner.

### `g_packetSender`

Current MCP facts:

- `xrefs_to 0x0067a7ec` returned `xref_count:489`, `returned:489`, `more:false`.
- `find_bytes ec a7 67 00` returned 489 matches.
- `get_bytes 0x0067a7ec+4` returned `00 00 00 00`.
- `get_global_value 0x0067a7ec` and `get_global_value dword_67A7EC` both returned `0x0`.

Interpretation:

- This report accepts the current support-doc source-facing name/type `Socket *g_packetSender`.
- `TakeOffInputPane` and [UID:0001M2] are consumers only.
- Do not resurrect stale `CashShopRequest *` aliases or feature-local sender ownership.

## Caller And Callee Evidence

`callees(database=ff68e691)` returned:

| Function | Callees |
| --- | --- |
| `0x005b2720` | `std::ctype<char>::do_narrow`, `sub_575380`, `sub_574BB0`, `@__security_check_cookie@4`, `sub_4F2920` |
| `0x005b27c0` | `sub_575380`, `sub_574BB0`, `@__security_check_cookie@4` |
| `0x005b2830` | `sub_4F2310`, `sub_4F2300`, `sub_5B27C0`, `@__security_check_cookie@4`, `sub_575380`, `sub_574BB0` |
| `0x005aa0c0` | `sub_4F4AA0`, `sub_4F0350`, `sub_4F28A0` |
| `0x00568cb0` | includes `sub_5B27C0` among the SelfLookPane click-path callees |

[UID:0001M2] caller set, current MCP:

- 28 direct code xrefs to `0x005b27c0`.
- SelfLookPane caller group in `sub_568CB0`: `0x005690b0`, `0x005690bf`, `0x005690ce`, `0x005690dd`, `0x005690ec`, `0x005690fb`, `0x0056910a`, `0x00569119`, `0x00569128`, `0x00569137`, `0x00569146`, `0x00569170`, `0x0056917f`, `0x0056918e`.
- TakeOff uppercase `A` caller group in `sub_5B2830`: `0x005b2873`, `0x005b287a`, `0x005b2881`, `0x005b2888`, `0x005b288f`, `0x005b2896`, `0x005b289d`, `0x005b28a4`, `0x005b28ab`, `0x005b28b2`, `0x005b28b9`, `0x005b28c0`, `0x005b28c7`, `0x005b28ce`.

This confirms the support-doc nuance:

- [UID:0001M2] is not a TakeOff class method.
- [UID:0001M2] is not SelfLook-owned.
- The typed single-slot TakeOff path emits opcode `0x1f` inline after `g_equipmentSlotKeys` match.
- The uppercase `A` all-equipment path is the TakeOff path that calls the helper.

## Positive Evidence

- Current MCP session `ff68e691` is healthy and IDB-backed.
- IDA recognizes the two class method bodies and helper body exactly at `0x005b2720`, `0x005b27c0`, and `0x005b2830`.
- End boundaries are proven by function sizes and `0xcc` padding runs.
- `0x005b2720` and `0x005b2830` have vtable-slot data routes at `0x0062f984` and `0x0062f974`.
- `0x005b27c0` has 28 code callers and no direct data-pointer/vtable route, matching a free helper.
- Raw constructor sibling [UID:0001M0] has exact bytes, vtable stores, prompt id `0x22`, and an inline factory mirror at `0x005aa0c0`.
- `g_equipmentSlotKeys` table bytes and single `0x005b28f0` data xref are current MCP-backed.
- `g_activeDialogCount` target refs and signed positive skip gates are current MCP-backed.
- `g_packetSender` high-fanout packet sender route and exact 489 refs are current MCP-backed.
- Current generated output already contains first-draft C++ for [UID:0001M2], and current MCP supports retaining that implementation.
- The class/file ownership route through [UID:0000EC] and [UID:0000KC] matches vtable family and source-neighborhood evidence.

## Negative Evidence And Rejected Alternatives

Rejected: aggregate C++ on [UID:0001M1].

- The target range contains two class virtual methods, one already-owned file-level helper child, and padding.
- Formal parent C++ would duplicate [UID:0001M2]'s helper body.
- Formal parent C++ would need unresolved event fields, command helper names, and virtual return conventions.

Rejected: treating [UID:0001M2] as `TakeOffInputPane::SendTakeOffPacket`.

- It is `__cdecl`, has no `this`, and has SelfLook callers.
- It has no vtable slot.
- The typed TakeOff table branch does not call it.

Rejected: treating [UID:0001M2] as SelfLookPane-owned.

- SelfLook provides 14 direct calls, but the implementation sits in the ItemActionInputPanes source neighborhood.
- The helper has no SelfLook state access.
- TakeOff contributes the other 14 direct calls and defines the fixed key-table selector domain.

Rejected: ProtocolSend/network ownership for [UID:0001M2] or the target aggregate.

- The body is feature-specific opcode `0x1f` equipment-removal logic.
- `g_packetSender` is a Socket-owned global consumed by many UI features.
- Calling `QueueAndSendPacket` is not source-unit ownership evidence.

Rejected: raw constructor direct-call/liveness route.

- `lookup_funcs 0x005b26e0` is Not a function.
- `xrefs_to 0x005b26e0` is zero.
- `find_bytes e0 26 5b 00` is zero.
- Inline factory mirror at `0x005aa0c0` proves constructor shape but not callable raw-start liveness.

Rejected: `*` as the all-equipment TakeOff command.

- Current MCP decompilation and disassembly compare to `0x0041` / uppercase `A`.

Rejected: modeling single-slot typed TakeOff as a call to [UID:0001M2].

- Current MCP decompilation shows the table branch writes opcode `0x1f` inline and sends length `2` directly.

Rejected: unsigned/zero-only gate for `g_activeDialogCount`.

- The target instruction sequence uses signed `jg`, so source-facing target logic should remain `<= 0` even though current IDB bytes read `0x00`.

## Source Placement And Ownership Ranking

### 1. [UID:0000EC] `TakeOffInputPane` class owner for [UID:0001M1] - accepted

Evidence:

- Vtable primary/secondary slots point to `0x005b2830` and `0x005b2720`.
- Raw constructor and inline command-factory mirror install the three TakeOffInputPane vtable views.
- The page's two class method bodies are TakeOff-specific.
- The direct class parent scores above gate and is already the current canonical owner.

Decision:

- Keep [UID:0001M1] owner/emitter [UID:0000EC].
- Keep blank aggregate C++.
- Document that the nested [UID:0001M2] helper is file-level and should not be re-emitted by the parent aggregate.

### 2. [UID:0000KC] `ItemActionInputPanes` source file - accepted as source-family/file route

Evidence:

- The whole TakeOff family sits in the direct item-action prompt address neighborhood.
- [UID:0001M2] is already source-ready as a file-level helper under [UID:0000KC].
- `g_equipmentSlotKeys` is routed through this source family.
- Wield/Wear sibling pages use the same aggregate pattern and adjacent helper policy.

Decision:

- Support docs should describe [UID:0000KC] as the source module/family.
- Do not change [UID:0001M1] canonical owner from class to file.

### 3. [UID:0001M2] exact helper child - accepted as separate source item

Evidence:

- Exact helper range is `0x005b27c0-0x005b2827`.
- It has code callers from TakeOff and SelfLook.
- It has no vtable slot and no `this`.
- It already has accepted first-draft C++.

Decision:

- Keep [UID:0001M2] as a separate child/source item.
- Target [UID:0001M1] should cross-reference it and avoid duplicate emission.

### 4. Raw constructor [UID:0001M0] - retained sibling, not folded into [UID:0001M1]

Evidence:

- Exact range ends at `0x005b2720`, just before target start.
- It is not an IDA function and has no direct xrefs/pointer route.
- Inline factory mirror proves the same source constructor shape.

Decision:

- Support-sync [UID:0001M0] with current MCP evidence if implementation scope allows.
- Do not fold it into [UID:0001M1].

## C++ Readiness And No-Code Proof

### Aggregate [UID:0001M1]

Formal C++ recommendation: keep blank.

Target-specific no-code proof:

- [UID:0001M1] is an aggregate/method-cluster, not one exact source function.
- The range includes [UID:0001M2], whose exact helper page already emits first-draft C++ through [UID:0000KC].
- The remaining source-bearing bodies `0x005b2720-0x005b27b3` and `0x005b2830-0x005b296b` do not have exact child pages.
- The key-event method depends on unresolved event argument field names at offsets `+0x04`, `+0x08`, and `+0x10a`.
- The submit/command method depends on unresolved source names/return types for `sub_4F2310` and `sub_4F2300`.
- The vtable slot roles are strong, but original virtual method names remain descriptive.
- Parent aggregate C++ would either duplicate [UID:0001M2] or paste multiple unrelated bodies into one reconstruction block, which violates the by-memory exact-range/source-item policy.

### Exact child candidate `0x005b2720-0x005b27b3`

Formal C++ recommendation on first child creation: blank.

Reason:

- Behavior is clear, but source-quality C++ would need event type and field names for the `?` shortcut, mode byte `4`, and event message byte `8`.
- It would also need the accepted source-facing name for the base `CharInputPane` virtual at `0x004f2920`.
- A draft using `a2[266]` or IDA-style event fields would not meet source-quality requirements.

### Exact child candidate `0x005b2830-0x005b296b`

Formal C++ recommendation on first child creation: blank.

Reason:

- Behavior is clear, but source-quality C++ would need source-facing names and return conventions for the command-input helpers at `0x004f2310` and `0x004f2300`.
- It would need a standardized method name for the primary `+0x48` virtual slot.
- The inline single-slot packet send can be written in human C++, but the surrounding input/helper API names are still too decompiler-shaped.

### Exact helper child [UID:0001M2]

Formal C++ recommendation: keep existing first-draft C++.

Reason:

- The helper has an exact one-function range, source-ready owner/emitter route [UID:0000KC], current MCP-confirmed body, current MCP-confirmed caller set, and source-facing global/helper names good enough for first draft.

## Score And Metadata Recommendation

Recommended [UID:0001M1] metadata after accepted implementation:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000EC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000EC
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Score rationale:

- Completion `87`: current report closes the MCP-evidence gap, exact function inventory, padding fences, vtable routes, helper split, raw-constructor sibling relationship, caller/callee facts, packet behavior, selector table, global dependencies, and source-placement reasoning. Completion remains below `90` because exact method child pages for `0x005b2720` and `0x005b2830` do not exist and support docs still need stale provenance cleanup.
- Confidence `89`: current MCP confirms the important binary facts directly. Confidence remains below near-final because source-facing virtual names, event field names, command-input helper APIs, and the `g_activeDialogCount` byte-init discrepancy are still unresolved.

No owner/emitter change is recommended:

- [UID:0000EC] remains the correct direct class owner for the aggregate.
- [UID:0000KC] remains the correct source-family/file context and [UID:0001M2] owner.

## Support-Doc Update Recommendation

Required if accepted for implementation:

- `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`
  - Raise metadata to `87/89`.
  - Replace stale/fallback/cached provenance with current MCP session `ff68e691`.
  - Add exact function inventory and padding ranges.
  - Add vtable slot bytes/routes `0x0062f984 -> 0x005b2720` and `0x0062f974 -> 0x005b2830`.
  - Clarify [UID:0001M2] is a file-level helper child already source-ready.
  - Clarify uppercase `A` calls [UID:0001M2] for all valid selectors, while typed single-slot path sends inline after scanning `g_equipmentSlotKeys`.
  - Add current no-code aggregate proof.

- `by-class/TakeOffInputPane.md`
  - Add current MCP-backed method split and slot route details.
  - Replace stale code-gate wording with the current no-aggregate-C++ rationale.
  - Clarify raw constructor sibling [UID:0001M0] no-function/no-xref/no-pointer state with inline factory mirror.
  - Clarify [UID:0001M2] is not a class method.

- `by-file/ItemActionInputPanes.md`
  - Add current MCP-backed TakeOff split details.
  - Keep [UID:0001M2] as file-level helper body and [UID:0001M1] as class aggregate.
  - Preserve source-family caveat and shared helper declaration/header caveat for SelfLook.
  - Supersede any B006 local-export-only/MCP-unavailable wording for [UID:0001M2] in this family with current MCP session `ff68e691`.

- `by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md`
  - Keep metadata and C++ unchanged.
  - Replace or supplement archived B006 local-export/fallback wording with current MCP session `ff68e691` verification: exact range, 28 callers, body, active-dialog gate, packet sender, and padding.

- `by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md`
  - Keep metadata and blank C++ unless supervisor requests broader re-score.
  - Add current MCP proof: not a function, decompile failure, zero xrefs, zero raw VA pointer hits, exact bytes, vtable stores, and `0x005aa0c0` inline factory mirror.

Optional or separate-scope support sync:

- `by-global/g_equipmentSlotKeys.md` and `by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md`
  - Current facts are already mostly present. Optional sync can add current MCP session `ff68e691` as fresh evidence and preserve that [UID:0001M2] shares selector IDs but does not read the table.

- `by-global/g_activeDialogCount.md` and `by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md`
  - Separate support reconciliation is advisable because current MCP reads the byte as `0x00`, while older docs record `0xff`. Do not let this target implementation silently repeat `0xff` as current evidence. The source expression `<= 0` remains supported by signed `jg`.

- `by-global/g_packetSender.md` and `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
  - No mandatory change. Existing Socket-owned route remains valid; optional sync can add this current target as another `QueueAndSendPacket` consumer.

- `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`
  - No mandatory change. Existing table already records TakeOff vtable slots, but optional sync can add current MCP session `ff68e691`.

Potential new child pages if supervisor accepts split work:

- `by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md`
  - Suggested owner/emitter [UID:0000EC].
  - Suggested initial score around `86/89`.
  - Blank formal C++ with event-field no-code proof.

- `by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md`
  - Suggested owner/emitter [UID:0000EC].
  - Suggested initial score around `87/89`.
  - Blank formal C++ with command-helper/source-name no-code proof.

The exact child filenames above are descriptive suggestions. If implementation creates them, the new UIDs must be assigned by the normal project/validator workflow before supervisor-owned coverage rows can be exact.

## Exact Supervisor-Owned Coverage Text

Do not edit `by-memory/-coverage-report.md` in the B-agent implementation callback. If the supervisor accepts this report and applies coverage text, replace the current [UID:0001M1] row with:

```text
    - [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md) 0x005b2720-0x005b296b | class-method-cluster | TakeOffInputPane : reconstructable : 87% : very strong : B002 MCP source-quality pass (session `ff68e691`) confirms exact function inventory `sub_5B2720` size `0x93`, `SendTakeOffPacket` size `0x67`, and `sub_5B2830` size `0x13b`, padding fences `0x005b27b3-0x005b27c0`, `0x005b2827-0x005b2830`, and `0x005b296b-0x005b2970`, vtable slot routes `0x0062f984 -> 0x005b2720` and `0x0062f974 -> 0x005b2830`, raw constructor sibling [UID:0001M0] no-function/no-xref/no-pointer state with `0x005aa0c0` inline factory mirror, `?` shortcut opcode `0x2d` length `1`, uppercase `A` all-equipment calls to [UID:0001M2] for selectors `1,2,3,4,6,7,8,13,14,16,20,21,22,23`, and typed single-slot scanning of `g_equipmentSlotKeys` followed by inline opcode `0x1f` send through `g_packetSender` when `g_activeDialogCount <= 0`; target remains blank-C++ aggregate pending exact method child pages and final event/command helper names.
```

The accepted implementation created exact method child pages. If the supervisor applies child coverage rows, add these rows in the same TakeOff memory area:

```text
    - [UID:00041L][0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut](by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md) 0x005b2720-0x005b27b3 | class-virtual-method | TakeOffInputPaneHandleTakeOffShortcut : reconstructable : 86% : very strong : B002 MCP source-quality implementation created exact child for `sub_5B2720` size `0x93`; session `ff68e691` confirms vtable route `0x0062f984 -> 0x005b2720`, no ordinary code caller or raw pointer-table route, event/ctype tests for narrowed `?`, event byte `+0x10a == 4`, and event byte `+0x04 == 8`, handled shortcut opcode `0x2d` length `1` through `g_packetSender`, and fallback to `CharInputPane`; blank C++ remains required until source-facing event argument and field names are standardized.
    - [UID:00041M][0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand](by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md) 0x005b2830-0x005b296b | class-virtual-method | TakeOffInputPaneProcessUnequipCommand : reconstructable : 87% : very strong : B002 MCP source-quality implementation created exact child for `sub_5B2830` size `0x13b`; session `ff68e691` confirms vtable route `0x0062f974 -> 0x005b2830`, no ordinary code caller or raw pointer-table route, one-character command gate, uppercase `A` all-equipment calls to [UID:0001M2] for selectors `1,2,3,4,6,7,8,13,14,16,20,21,22,23`, typed single-slot scan of `g_equipmentSlotKeys`, inline opcode `0x1f` send through `g_packetSender` when `g_activeDialogCount <= 0`, and blank C++ until source-facing command helper names and return convention are standardized.
```

## Expected Validators After Accepted Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0001M1-TakeOffInputPane-source-quality-removed.md](0001M1-TakeOffInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional global/vtable support docs are edited, also run scoped validators for each changed file. If exact child pages are created, validate their real relative paths after creation.

## Open Questions And Score Impact

Closed by current MCP:

- Exact [UID:0001M1] internal function and padding boundaries.
- Raw constructor sibling remains no-function/no-xref/no-pointer.
- Inline factory mirror proves constructor shape without creating a raw-start route.
- [UID:0001M2] exact range, body, caller set, and file-level helper role.
- `A` is the all-equipment command.
- Typed single-slot path emits opcode `0x1f` inline after table scan.
- `g_equipmentSlotKeys` bytes and one xref.
- `g_packetSender` current 489-ref high-fanout state.

Still open:

- Original virtual names for `0x005b2720` and `0x005b2830`.
- Source-facing event argument type and field names for offsets `+0x04`, `+0x08`, and `+0x10a`.
- Source-facing command-input helper names and return types for `0x004f2310` and `0x004f2300`.
- Final declaration/init convention for `g_activeDialogCount`; current MCP byte is `0x00`, older docs say `0xff`, while target signed-gate behavior remains clear.
- Whether exact child pages should be created in the immediate implementation callback or deferred to a split-specific callback.

Impact:

- These open questions cap [UID:0001M1] below near-final scores.
- They block aggregate C++.
- They do not block a modest metadata/coverage raise above `86/86`.

## Implementation Tracking Checklist

Implementation callback state: accepted non-coverage items are checked. No coverage report was edited by B002; `by-memory/-coverage-report.md` still contains the stale `0001M1` row and no [UID:00041L]/[UID:00041M] rows as of the post-validator check.

- [x] Update `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md` to `COMPLETION:87`, `CONFIDENCE:89`, preserve owner/emitter [UID:0000EC], blank C++, and incorporate current MCP session `ff68e691` evidence at report-level detail. Proof: header is `87/89`, owner/emitter remain `0000EC`, C++ block is blank, and sections now record current MCP function inventory, exact padding, vtable routes, helper split, uppercase `A`, typed single-slot inline send, current `g_activeDialogCount <= 0` caveat, child pages [UID:00041L]/[UID:00041M], and aggregate no-code proof.
- [x] Update `by-class/TakeOffInputPane.md` with current MCP-backed boundaries, vtable slots, helper split, raw constructor sibling caveat, uppercase `A` branch, single-slot inline send, and no-aggregate-C++ rationale. Proof: method table and evidence notes now link [UID:00041L]/[UID:00041M], preserve [UID:0001M2] as file-level helper, cite session `ff68e691`, and supersede historical numeric code-gate wording with source-quality no-code rationale.
- [x] Update `by-file/ItemActionInputPanes.md` with current MCP-backed TakeOff source-family facts, [UID:0001M2] file-level helper disposition, and shared declaration/header caveat. Proof: proposed contents and boundary notes now include [UID:0001M0], [UID:0001M1], [UID:00041L], [UID:0001M2], [UID:00041M], current MCP `ff68e691`, helper caller split, vtable/pointer-route evidence, and blank aggregate C++ rationale.
- [x] Update `by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md` only to supersede local-export/MCP-unavailable provenance with current MCP session `ff68e691`; keep metadata and C++ unchanged. Proof: added current MCP section with range/decompile/callee/xref/no-data-pointer/padding facts; header remains `89/90`, owner/emitter [UID:0000KC], and existing `void SendTakeOffPacket(char equipmentSlotSelector)` C++ is unchanged.
- [x] Update `by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md` with current MCP no-function/no-xref/no-pointer/decompile-failure proof and `0x005aa0c0` inline factory mirror; keep blank C++. Proof: added current MCP `ff68e691` section with raw bytes, decompile failure, zero xrefs, zero pointer hits, disassembly roles, and factory mirror; C++ remains blank with no-route/source-form proof.
- [x] Optional/separate: reconcile `g_activeDialogCount` support docs so current IDB byte `0x00` is not confused with older `0xff` evidence while preserving signed `<= 0` target semantics. Proof: not edited by callback scope; target/support docs avoid presenting `0xff` as a current-session fact and explicitly preserve the current MCP `0x00` versus historical-doc caveat.
- [x] Optional/separate: add current MCP `ff68e691` refresh notes to `g_equipmentSlotKeys`, `g_packetSender`, and `ItemActionInputPaneVtableFamily` support docs if supervisor wants provenance sync. Proof: not edited because required target/class/file/helper docs already carry the current facts at accepted scope; optional global/vtable docs remain separate-scope.
- [x] Optional/split: create exact child page `0x005b2720-0x005b27b3` for the shortcut/key-event method if accepted; assign owner/emitter only through the normal by-structure gates and keep C++ blank unless source-facing event names are standardized. Proof: created [UID:00041L] `by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md`, metadata `86/89`, owner/emitter `0000EC`, blank formal C++, with event-field no-code proof.
- [x] Optional/split: create exact child page `0x005b2830-0x005b296b` for the submit/command method if accepted; assign owner/emitter only through the normal by-structure gates and keep C++ blank unless source-facing command helper names are standardized. Proof: created [UID:00041M] `by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md`, metadata `87/89`, owner/emitter `0000EC`, blank formal C++, with command-helper/source-name no-code proof.
- [x] Supervisor-owned: replace the [UID:0001M1] row in `by-memory/-coverage-report.md` with the exact row supplied above if accepted, and optionally add [UID:00041L]/[UID:00041M] rows now that child UIDs exist. Proof: not edited by B002; post-validator `Select-String` shows the coverage report still has stale [UID:0001M1] `78%` row and no child UID rows.
- [x] Validator: `python .\tools\validator.py --mode file --file by-memory\0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md --apply --queue-timeout 240`. Result: exit code `0`, observable `ok`-line count `0`; side effects included metadata registry updates for [UID:00041L], autogen/registry refresh, and no coverage row insertion.
- [x] Validator: `python .\tools\validator.py --mode file --file by-memory\0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md --apply --queue-timeout 240`. Result: exit code `0`, observable `ok`-line count `0`; side effects included UID allocation/registry updates for [UID:00041M], autogen/registry refresh, and no coverage row insertion.
- [x] Validator: `python .\tools\validator.py --mode file --file by-memory\0x005b2720-0x005b296b.TakeOffInputPane.md --apply --queue-timeout 240`. Result: exit code `0`, observable `ok`-line count `0`; side effects included UID link insertion for [UID:0001M2] mentions and expected `project-level/-auto-completion-stats.md` row removals for [UID:0001M1].
- [x] Validator: `python .\tools\validator.py --mode file --file by-class\TakeOffInputPane.md --apply --queue-timeout 240`. Result: exit code `0`, observable `ok`-line count `0`; after final wording cleanup the validator was rerun and again exited `0` with `ok`-line count `0`, side effects `stats_row_update 0000EC` plus autogen/registry refreshes.
- [x] Validator: `python .\tools\validator.py --mode file --file by-file\ItemActionInputPanes.md --apply --queue-timeout 240`. Result: exit code `0`, observable `ok`-line count `0`; side effects included UID link insertion for [UID:0001M2], [UID:00041L], and [UID:00041M] mentions plus autogen/registry refreshes.
- [x] Validator: `python .\tools\validator.py --mode file --file by-memory\0x005b27c0-0x005b2827.SendTakeOffPacket.md --apply --queue-timeout 240`. Result: exit code `0`, observable `ok`-line count `0`; after final wording cleanup the validator was rerun and again exited `0` with `ok`-line count `0`, side effects `stats_incremental_noop 0001M2` plus autogen/registry refreshes.
- [x] Validator: `python .\tools\validator.py --mode file --file by-memory\0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md --apply --queue-timeout 240`. Result: exit code `0`, observable `ok`-line count `0`; after final wording cleanup the validator was rerun and again exited `0` with `ok`-line count `0`, side effects `stats_incremental_noop 0001M0` plus autogen/registry refreshes.
- [x] Validator: run equivalent scoped validators for any optional globals/vtable/exact-child docs edited in an accepted implementation callback. Proof: no optional globals/vtable docs were edited; exact-child validators are recorded above.

## Changed Files In This Report-Only Pass

Created:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0001M1-TakeOffInputPane-source-quality.md
```

Not edited:

- `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`
- `by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md`
- `by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md`
- `by-class/TakeOffInputPane.md`
- `by-file/ItemActionInputPanes.md`
- Any by-global/by-type support docs
- Any `-coverage-report.md`
- Generated/project-level files
- IDA DB or tool state

## Changed Files In Accepted Implementation Callback

By-* docs changed or created:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b2720-0x005b296b.TakeOffInputPane.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-class\TakeOffInputPane.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-file\ItemActionInputPanes.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b27c0-0x005b2827.SendTakeOffPacket.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md
```

Report updated:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0001M1-TakeOffInputPane-source-quality.md
```

Validator side effects observed: autogen/registry refreshes, UID link insertions, and `project-level/-auto-completion-stats.md` row removals for [UID:0001M1]. Coverage reports were not intentionally edited; the current by-memory coverage report still shows stale [UID:0001M1] text and no [UID:00041L]/[UID:00041M] rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001M1-TakeOffInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0001M1"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001M1-TakeOffInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001M1-TakeOffInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001M1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
