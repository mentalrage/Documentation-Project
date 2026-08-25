*** UID:0004P6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct UserCreateColorSwatchItem
{
    int row;
    int colorValue;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserCreateAppearanceControlLayouts

## Status And Source Disposition

- Reconstructable NexusTK source type support for the five appearance-control classes in [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md).
- The only standalone declaration emitted by this page is the shared eight-byte `UserCreateColorSwatchItem`. The five complete class declarations remain on their direct by-class pages so aggregate and class output cannot duplicate.
- Exact field offsets and sizes are binary facts; descriptive member names are the highest-probability consistent human-source model in the absence of authentic source or PDB symbols.

## UserHairSelectControlPane Layout

| Offset | Type | Source field / role |
| --- | --- | --- |
| inherited through `+0x107` | `ControlPane` | Complete base and inherited control flags, including control byte at `+0xff`. |
| `+0x108` | `unsigned char` | `m_reservedState`, initialized to zero. |
| `+0x10a` | `short` | `m_selectedHair`. |
| `+0x10c` | `unsigned char` | `m_gender`, selecting one of two frame banks. |
| `+0x10d` | `unsigned char` | `m_hairColor`. |
| `+0x10e` | `bool` | `m_mouseTracking`. |
| `+0x110` | `unsigned short[18]` | Male `m_hairPartFrames[0]`. |
| `+0x134` | `unsigned short[18]` | Female `m_hairPartFrames[1]`. |
| `+0x158` | `unsigned char` | `m_columnCount`, exact value 9. |
| `+0x15c` | `RectBounds` | Local `m_hitBounds`. |
| size `0x16c` |  | Exact caller allocation and full field extent. |

Grid constants are 9 columns by 2 rows, with 82x58 cells. Constructor, mouse, paint, selection, and mode-setter children agree on every listed offset.

## UserFaceSelectControlPane Layout

| Offset | Type | Source field / role |
| --- | --- | --- |
| inherited through `+0x107` | `ControlPane` | Complete base and inherited control flags. |
| `+0x108` | `unsigned char` | `m_reservedState`, initialized to zero. |
| `+0x10a` | `short` | `m_selectedFace`. |
| `+0x10c` | `unsigned char` | `m_gender`. |
| `+0x10d` | `unsigned char` | `m_faceColor`. |
| `+0x10e` | `bool` | `m_mouseTracking`. |
| `+0x110` | `unsigned short[12]` | Male `m_facePartIds[0]`. |
| `+0x128` | `unsigned short[12]` | Female `m_facePartIds[1]`. |
| `+0x140` | `unsigned char` | `m_columnCount`, exact value 6. |
| `+0x144` | `RectBounds` | Local `m_hitBounds`. |
| size `0x154` |  | Exact caller allocation and full field extent. |

Grid constants are 6 columns by 2 rows with the same 82x58 cells. Both part-id banks are the exact 0..11 sequence.

## UserCreatePreviewControlPane Layout

| Offset | Type | Source field / role |
| --- | --- | --- |
| inherited through `+0x107` | `ControlPane` | Complete base. |
| `+0x108` | `unsigned short` | `m_faceFrameBase`, stored as source face frame plus 200. |
| `+0x10a` | `unsigned short` | `m_hairFrame`. |
| `+0x10c` | `unsigned char` | `m_gender`. |
| `+0x10d` | `unsigned char` | `m_direction`, initialized to 2 and advanced modulo 4. |
| `+0x10e` | `unsigned char` | `m_hairColor`. |
| `+0x10f` | `unsigned char` | `m_faceColor`. |
| `+0x110` | `unsigned char` | `m_reservedState`, initialized to zero. |
| size `0x114` |  | Exact caller allocation and full field extent. |

The descriptor builder leaves `kind` caller-owned; paint supplies `0x50`. The lower-arity update overload clears both colors, while the full overload writes all five appearance inputs.

## Hair And Face Color List Layouts

| Offset | Type | Source field / role |
| --- | --- | --- |
| inherited through `+0x14b` | `ListPane` | Base storage, selection, and list behavior. |
| `+0x14c` | `CreateUserDialogPane *` | Non-owning `m_owner`. |
| size `0x150` |  | Exact allocation for both list classes. |

`UserCreateColorSwatchItem` is exactly eight bytes: `row` at +0 and `colorValue` at +4. Constructors pass `sizeof(UserCreateColorSwatchItem)` to the base, add 16 copied entries, and draw/getter methods consume `colorValue`.

## Cross-Validation And Ownership

- Allocation sizes are proved at CreateUserDialogPane construction calls; method-level field reads/writes and contiguous vtable families independently corroborate each class boundary.
- The shared swatch type belongs to the dedicated appearance-controls header because both list classes use it. Assigning it to one list, the dialog, ListPane, PaletteLib, or the read-only table would create the wrong source dependency.
- Vptr stores, EventHandler/TimerHandler subobject adjustments, deleting destructors, and adjustor thunks are compiler ABI evidence and do not appear in the formal type declaration.
- No raw byte arrays, offset comments, decompiler names, ownership transfer, palette deletion, or guards absent from the binary are introduced.
- [UID:0001A6][0x00501150-0x00502383.UserCreateAppearanceSelectorControls](by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md) remains the exact non-emitting address index; method pages and class pages carry source output.

## Score Rationale

- Completion 90 reflects exact sizes, offsets, field widths, grid constants, cross-method validation, source ownership, and the final shared type declaration.
- Confidence 92 reflects direct allocation/field evidence with a bounded descriptive-name cap from the stripped binary.

