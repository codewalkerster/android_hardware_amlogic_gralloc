/*
 *  ion_wrapper.h
 *
 * Memory Allocator functions for ion
 *
 *   Copyright 2011 Google, Inc
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <errno.h>
#include <fcntl.h>
#include <linux/ion.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

#include <ion/ion.h>
#include <log/log.h>


int ion_open();
int ion_close(int fd);
static int ion_ioctl(int fd, int req, void *arg);
int ion_alloc(int fd, size_t len, size_t align, unsigned int heap_mask,
		              unsigned int flags, ion_user_handle_t *handle);
int ion_free(int fd, ion_user_handle_t handle);
int ion_map(int fd, ion_user_handle_t handle, size_t length, int prot,
		            int flags, off_t offset, unsigned char **ptr, int *map_fd);
int ion_share(int fd, ion_user_handle_t handle, int *share_fd);
int ion_alloc_fd(int fd, size_t len, size_t align, unsigned int heap_mask,
		                 unsigned int flags, int *handle_fd);
int ion_import(int fd, int share_fd, ion_user_handle_t *handle);
int ion_sync_fd(int fd, int handle_fd);
